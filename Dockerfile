# Multi-stage build for Qt application
FROM ubuntu:22.04 AS builder

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libgl1-mesa-dev \
    libglu1-mesa-dev \
    libxcb-xinerama0 \
    libxkbcommon-x11-0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-xinerama0 \
    libxcb-xinput0 \
    libxcb-xfixes0 \
    libx11-xcb1 \
    libxcb-shape0 \
    libxcb-sync1 \
    libxrender1 \
    libxi6 \
    libfontconfig1 \
    libfreetype6 \
    libxext6 \
    libx11-6 \
    libice6 \
    libsm6 \
    libxcb1 \
    libxcb-glx0 \
    qt6-base-dev \
    qt6-base-dev-tools \
    qmake6 \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy project files
COPY . .

# Build the application
RUN qmake6 CircuitBuilder.pro && make -j$(nproc)

# Runtime stage
FROM ubuntu:22.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=UTC

# Install runtime dependencies
RUN apt-get update && apt-get install -y \
    qt6-base-dev \
    libgl1-mesa-glx \
    libglu1-mesa \
    libxcb-xinerama0 \
    libxkbcommon-x11-0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-keysyms1 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-xinerama0 \
    libxcb-xinput0 \
    libxcb-xfixes0 \
    libx11-xcb1 \
    libxcb-shape0 \
    libxcb-sync1 \
    libxrender1 \
    libxi6 \
    libfontconfig1 \
    libfreetype6 \
    libxext6 \
    libx11-6 \
    libice6 \
    libsm6 \
    libxcb1 \
    libxcb-glx0 \
    x11-apps \
    xvfb \
    && rm -rf /var/lib/apt/lists/*

# Create non-root user
RUN useradd -m -s /bin/bash appuser

# Set working directory
WORKDIR /app

# Copy built application from builder stage
COPY --from=builder /app/CircuitBuilderApp /app/
COPY --from=builder /app/*.png /app/
COPY --from=builder /app/*.jpg /app/

# Change ownership
RUN chown -R appuser:appuser /app

# Switch to non-root user
USER appuser

# Set display for GUI applications
ENV DISPLAY=:99
ENV QT_QPA_PLATFORM=xcb

# Entry point for running with virtual display
CMD ["sh", "-c", "Xvfb :99 -screen 0 1024x768x24 & sleep 2 && ./CircuitBuilderApp"]