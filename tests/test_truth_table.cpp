#include <gtest/gtest.h>
#include "../TruthTable.h"
#include "../Circuit.h"
#include "../Gate.h"

class TruthTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        circuit = new Circuit();
    }

    void TearDown() override {
        delete circuit;
    }

    Circuit* circuit;
};

TEST_F(TruthTableTest, SimpleTruthTableTest) {
    // Create simple AND circuit
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 50));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(400, 50));

    circuit->addGate(input1);
    circuit->addGate(input2);
    circuit->addGate(andGate);
    circuit->addGate(output);

    circuit->connectGates(input1, andGate, 0);
    circuit->connectGates(input2, andGate, 1);
    circuit->connectGates(andGate, output, 0);

    TruthTable truthTable(circuit);
    truthTable.generate();

    auto table = truthTable.getTable();
    EXPECT_EQ(table.size(), 4); // 2^2 combinations

    // Verify AND truth table
    EXPECT_FALSE(table[0].outputs[0]); // 0 AND 0 = 0
    EXPECT_FALSE(table[1].outputs[0]); // 0 AND 1 = 0
    EXPECT_FALSE(table[2].outputs[0]); // 1 AND 0 = 0
    EXPECT_TRUE(table[3].outputs[0]);  // 1 AND 1 = 1
}

TEST_F(TruthTableTest, MultiOutputTruthTableTest) {
    // Create circuit with two outputs
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 50));
    Gate* orGate = new Gate(GateType::OR, QPointF(200, 150));
    Gate* output1 = new Gate(GateType::OUTPUT, QPointF(400, 50));
    Gate* output2 = new Gate(GateType::OUTPUT, QPointF(400, 150));

    circuit->addGate(input1);
    circuit->addGate(input2);
    circuit->addGate(andGate);
    circuit->addGate(orGate);
    circuit->addGate(output1);
    circuit->addGate(output2);

    circuit->connectGates(input1, andGate, 0);
    circuit->connectGates(input2, andGate, 1);
    circuit->connectGates(andGate, output1, 0);

    circuit->connectGates(input1, orGate, 0);
    circuit->connectGates(input2, orGate, 1);
    circuit->connectGates(orGate, output2, 0);

    TruthTable truthTable(circuit);
    truthTable.generate();

    auto table = truthTable.getTable();
    EXPECT_EQ(table.size(), 4);
    EXPECT_EQ(table[0].outputs.size(), 2);

    // Verify AND output (output1)
    EXPECT_FALSE(table[0].outputs[0]); // 0 AND 0 = 0
    EXPECT_FALSE(table[1].outputs[0]); // 0 AND 1 = 0
    EXPECT_FALSE(table[2].outputs[0]); // 1 AND 0 = 0
    EXPECT_TRUE(table[3].outputs[0]);  // 1 AND 1 = 1

    // Verify OR output (output2)
    EXPECT_FALSE(table[0].outputs[1]); // 0 OR 0 = 0
    EXPECT_TRUE(table[1].outputs[1]);  // 0 OR 1 = 1
    EXPECT_TRUE(table[2].outputs[1]);  // 1 OR 0 = 1
    EXPECT_TRUE(table[3].outputs[1]);  // 1 OR 1 = 1
}

TEST_F(TruthTableTest, ThreeInputTruthTableTest) {
    // Create 3-input circuit
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* input3 = new Gate(GateType::INPUT, QPointF(0, 200));
    Gate* andGate1 = new Gate(GateType::AND, QPointF(200, 50));
    Gate* orGate = new Gate(GateType::OR, QPointF(400, 125));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(600, 125));

    circuit->addGate(input1);
    circuit->addGate(input2);
    circuit->addGate(input3);
    circuit->addGate(andGate1);
    circuit->addGate(orGate);
    circuit->addGate(output);

    // (A AND B) OR C
    circuit->connectGates(input1, andGate1, 0);
    circuit->connectGates(input2, andGate1, 1);
    circuit->connectGates(andGate1, orGate, 0);
    circuit->connectGates(input3, orGate, 1);
    circuit->connectGates(orGate, output, 0);

    TruthTable truthTable(circuit);
    truthTable.generate();

    auto table = truthTable.getTable();
    EXPECT_EQ(table.size(), 8); // 2^3 combinations

    // Test a few combinations
    EXPECT_FALSE(table[0].outputs[0]); // (0 AND 0) OR 0 = 0
    EXPECT_TRUE(table[1].outputs[0]);  // (0 AND 0) OR 1 = 1
    EXPECT_TRUE(table[7].outputs[0]);  // (1 AND 1) OR 1 = 1
}

TEST_F(TruthTableTest, EmptyCircuitTest) {
    TruthTable truthTable(circuit);
    truthTable.generate();

    auto table = truthTable.getTable();
    EXPECT_EQ(table.size(), 0);
}

TEST_F(TruthTableTest, InputOnlyCircuitTest) {
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));

    circuit->addGate(input1);
    circuit->addGate(input2);

    TruthTable truthTable(circuit);
    truthTable.generate();

    auto table = truthTable.getTable();
    EXPECT_EQ(table.size(), 4); // 2^2 combinations
    EXPECT_EQ(table[0].outputs.size(), 0); // No outputs
}