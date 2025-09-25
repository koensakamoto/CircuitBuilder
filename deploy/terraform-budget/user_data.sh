#!/bin/bash

# Update system
yum update -y

# Install Docker
yum install -y docker
systemctl start docker
systemctl enable docker

# Install AWS CLI
yum install -y aws-cli

# Add ec2-user to docker group
usermod -a -G docker ec2-user

# Configure AWS region
export AWS_DEFAULT_REGION=${AWS_DEFAULT_REGION:-us-east-1}

# Login to ECR
aws ecr get-login-password --region $AWS_DEFAULT_REGION | docker login --username AWS --password-stdin ${ecr_registry}

# Pull and run the container
docker pull ${ecr_registry}:latest || echo "No image available yet"

# Create systemd service for the application
cat > /etc/systemd/system/circuitbuilder.service <<EOF
[Unit]
Description=CircuitBuilder Application
After=docker.service
Requires=docker.service

[Service]
Type=simple
Restart=always
RestartSec=10
ExecStartPre=-/usr/bin/docker stop circuitbuilder
ExecStartPre=-/usr/bin/docker rm circuitbuilder
ExecStartPre=/usr/bin/docker pull ${ecr_registry}:latest
ExecStart=/usr/bin/docker run --name circuitbuilder \
  -p 80:80 \
  -p 8080:8080 \
  -e DISPLAY=:99 \
  -e QT_QPA_PLATFORM=offscreen \
  ${ecr_registry}:latest

[Install]
WantedBy=multi-user.target
EOF

# Enable and start the service
systemctl daemon-reload
systemctl enable circuitbuilder.service
systemctl start circuitbuilder.service

# Create health check endpoint
cat > /usr/local/bin/health-check.sh <<'EOF'
#!/bin/bash
if docker ps | grep -q circuitbuilder; then
  echo "Healthy"
  exit 0
else
  echo "Unhealthy"
  exit 1
fi
EOF

chmod +x /usr/local/bin/health-check.sh

# Setup CloudWatch logging (optional)
yum install -y amazon-cloudwatch-agent