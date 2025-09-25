#include <gtest/gtest.h>
#include "../Circuit.h"
#include "../Gate.h"
#include "../TruthTable.h"

class IntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        circuit = new Circuit();
    }

    void TearDown() override {
        delete circuit;
    }

    Circuit* circuit;
};

TEST_F(IntegrationTest, HalfAdderCircuitTest) {
    // Build a half-adder circuit
    // Sum = A XOR B
    // Carry = A AND B

    Gate* inputA = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* inputB = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* xorGate = new Gate(GateType::XOR, QPointF(200, 50));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 150));
    Gate* sumOutput = new Gate(GateType::OUTPUT, QPointF(400, 50));
    Gate* carryOutput = new Gate(GateType::OUTPUT, QPointF(400, 150));

    circuit->addGate(inputA);
    circuit->addGate(inputB);
    circuit->addGate(xorGate);
    circuit->addGate(andGate);
    circuit->addGate(sumOutput);
    circuit->addGate(carryOutput);

    circuit->connectGates(inputA, xorGate, 0);
    circuit->connectGates(inputB, xorGate, 1);
    circuit->connectGates(xorGate, sumOutput, 0);

    circuit->connectGates(inputA, andGate, 0);
    circuit->connectGates(inputB, andGate, 1);
    circuit->connectGates(andGate, carryOutput, 0);

    // Test all combinations
    inputA->setState(false);
    inputB->setState(false);
    circuit->evaluate();
    EXPECT_FALSE(sumOutput->getState());   // 0 + 0 = 0 (sum)
    EXPECT_FALSE(carryOutput->getState()); // 0 + 0 = 0 (carry)

    inputA->setState(false);
    inputB->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(sumOutput->getState());    // 0 + 1 = 1 (sum)
    EXPECT_FALSE(carryOutput->getState()); // 0 + 1 = 0 (carry)

    inputA->setState(true);
    inputB->setState(false);
    circuit->evaluate();
    EXPECT_TRUE(sumOutput->getState());    // 1 + 0 = 1 (sum)
    EXPECT_FALSE(carryOutput->getState()); // 1 + 0 = 0 (carry)

    inputA->setState(true);
    inputB->setState(true);
    circuit->evaluate();
    EXPECT_FALSE(sumOutput->getState());   // 1 + 1 = 0 (sum)
    EXPECT_TRUE(carryOutput->getState());  // 1 + 1 = 1 (carry)
}

TEST_F(IntegrationTest, MultiplexerCircuitTest) {
    // Build a 2:1 multiplexer
    // Output = (NOT S AND A) OR (S AND B)

    Gate* inputA = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* inputB = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* selector = new Gate(GateType::INPUT, QPointF(0, 200));
    Gate* notGate = new Gate(GateType::NOT, QPointF(100, 200));
    Gate* andGate1 = new Gate(GateType::AND, QPointF(200, 50));
    Gate* andGate2 = new Gate(GateType::AND, QPointF(200, 150));
    Gate* orGate = new Gate(GateType::OR, QPointF(400, 100));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(600, 100));

    circuit->addGate(inputA);
    circuit->addGate(inputB);
    circuit->addGate(selector);
    circuit->addGate(notGate);
    circuit->addGate(andGate1);
    circuit->addGate(andGate2);
    circuit->addGate(orGate);
    circuit->addGate(output);

    // Connect NOT S
    circuit->connectGates(selector, notGate, 0);

    // Connect NOT S AND A
    circuit->connectGates(notGate, andGate1, 0);
    circuit->connectGates(inputA, andGate1, 1);

    // Connect S AND B
    circuit->connectGates(selector, andGate2, 0);
    circuit->connectGates(inputB, andGate2, 1);

    // Connect OR gate and output
    circuit->connectGates(andGate1, orGate, 0);
    circuit->connectGates(andGate2, orGate, 1);
    circuit->connectGates(orGate, output, 0);

    // Test: when selector = 0, output should equal A
    selector->setState(false);
    inputA->setState(false);
    inputB->setState(true);
    circuit->evaluate();
    EXPECT_FALSE(output->getState()); // Output = A = 0

    inputA->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState()); // Output = A = 1

    // Test: when selector = 1, output should equal B
    selector->setState(true);
    inputA->setState(false);
    inputB->setState(false);
    circuit->evaluate();
    EXPECT_FALSE(output->getState()); // Output = B = 0

    inputB->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState()); // Output = B = 1
}

TEST_F(IntegrationTest, DeMorgansLawTest) {
    // Verify De Morgan's Law: NOT(A AND B) = (NOT A) OR (NOT B)

    // Build left side: NOT(A AND B)
    Gate* inputA1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* inputB1 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 50));
    Gate* notGate1 = new Gate(GateType::NOT, QPointF(400, 50));
    Gate* output1 = new Gate(GateType::OUTPUT, QPointF(600, 50));

    circuit->addGate(inputA1);
    circuit->addGate(inputB1);
    circuit->addGate(andGate);
    circuit->addGate(notGate1);
    circuit->addGate(output1);

    circuit->connectGates(inputA1, andGate, 0);
    circuit->connectGates(inputB1, andGate, 1);
    circuit->connectGates(andGate, notGate1, 0);
    circuit->connectGates(notGate1, output1, 0);

    // Build right side: (NOT A) OR (NOT B)
    Gate* inputA2 = new Gate(GateType::INPUT, QPointF(0, 200));
    Gate* inputB2 = new Gate(GateType::INPUT, QPointF(0, 300));
    Gate* notGate2 = new Gate(GateType::NOT, QPointF(200, 200));
    Gate* notGate3 = new Gate(GateType::NOT, QPointF(200, 300));
    Gate* orGate = new Gate(GateType::OR, QPointF(400, 250));
    Gate* output2 = new Gate(GateType::OUTPUT, QPointF(600, 250));

    circuit->addGate(inputA2);
    circuit->addGate(inputB2);
    circuit->addGate(notGate2);
    circuit->addGate(notGate3);
    circuit->addGate(orGate);
    circuit->addGate(output2);

    circuit->connectGates(inputA2, notGate2, 0);
    circuit->connectGates(inputB2, notGate3, 0);
    circuit->connectGates(notGate2, orGate, 0);
    circuit->connectGates(notGate3, orGate, 1);
    circuit->connectGates(orGate, output2, 0);

    // Test all combinations and verify both sides are equal
    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            inputA1->setState(a);
            inputB1->setState(b);
            inputA2->setState(a);
            inputB2->setState(b);

            circuit->evaluate();

            EXPECT_EQ(output1->getState(), output2->getState())
                << "De Morgan's Law failed for A=" << a << ", B=" << b;
        }
    }
}

TEST_F(IntegrationTest, LargeCircuitPerformanceTest) {
    // Create a larger circuit to test performance
    const int numInputs = 10;
    std::vector<Gate*> inputs;
    std::vector<Gate*> gates;

    // Create inputs
    for (int i = 0; i < numInputs; i++) {
        Gate* input = new Gate(GateType::INPUT, QPointF(0, i * 50));
        inputs.push_back(input);
        circuit->addGate(input);
    }

    // Create a complex circuit with multiple layers
    for (int layer = 0; layer < 5; layer++) {
        for (int i = 0; i < numInputs / 2; i++) {
            Gate* gate = new Gate(GateType::AND, QPointF((layer + 1) * 200, i * 100));
            gates.push_back(gate);
            circuit->addGate(gate);

            if (layer == 0) {
                // Connect to inputs
                if (i * 2 < inputs.size()) {
                    circuit->connectGates(inputs[i * 2], gate, 0);
                }
                if (i * 2 + 1 < inputs.size()) {
                    circuit->connectGates(inputs[i * 2 + 1], gate, 1);
                }
            } else {
                // Connect to previous layer
                int prevLayerStart = (layer - 1) * (numInputs / 2);
                if (prevLayerStart + i < gates.size()) {
                    circuit->connectGates(gates[prevLayerStart + i], gate, 0);
                }
                if (prevLayerStart + i + 1 < gates.size()) {
                    circuit->connectGates(gates[prevLayerStart + i + 1], gate, 1);
                }
            }
        }
    }

    // Add output
    Gate* output = new Gate(GateType::OUTPUT, QPointF(1200, 200));
    circuit->addGate(output);
    if (!gates.empty()) {
        circuit->connectGates(gates.back(), output, 0);
    }

    // Set random input values and evaluate
    for (auto input : inputs) {
        input->setState(rand() % 2);
    }

    // Measure evaluation time (simple test that it completes)
    auto start = std::chrono::high_resolution_clock::now();
    circuit->evaluate();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Circuit should evaluate in reasonable time (< 100ms)
    EXPECT_LT(duration.count(), 100);
}