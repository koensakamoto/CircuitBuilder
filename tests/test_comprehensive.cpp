#include <gtest/gtest.h>
#include "../Gate.h"

class GateTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

// Basic Gate Creation Tests
TEST_F(GateTest, BasicGateCreation) {
    Gate gate;
    EXPECT_FALSE(gate.getSignal()); // Default signal should be false
}

TEST_F(GateTest, GateTypeCreation) {
    Gate andGate(GateType::AND_GATE);
    EXPECT_EQ(andGate.getGateType(), GateType::AND_GATE);
    EXPECT_FALSE(andGate.getSignal());
}

TEST_F(GateTest, AllGateTypes) {
    Gate inputGate(GateType::INPUT);
    Gate outputGate(GateType::OUTPUT);
    Gate andGate(GateType::AND_GATE);
    Gate orGate(GateType::OR_GATE);
    Gate inverter(GateType::INVERTER);
    Gate norGate(GateType::NOR_GATE);
    Gate nandGate(GateType::NAND_GATE);
    Gate xorGate(GateType::XOR_GATE);
    Gate xnorGate(GateType::XNOR_GATE);

    EXPECT_EQ(inputGate.getGateType(), GateType::INPUT);
    EXPECT_EQ(outputGate.getGateType(), GateType::OUTPUT);
    EXPECT_EQ(andGate.getGateType(), GateType::AND_GATE);
    EXPECT_EQ(orGate.getGateType(), GateType::OR_GATE);
    EXPECT_EQ(inverter.getGateType(), GateType::INVERTER);
    EXPECT_EQ(norGate.getGateType(), GateType::NOR_GATE);
    EXPECT_EQ(nandGate.getGateType(), GateType::NAND_GATE);
    EXPECT_EQ(xorGate.getGateType(), GateType::XOR_GATE);
    EXPECT_EQ(xnorGate.getGateType(), GateType::XNOR_GATE);
}

// Signal Tests
TEST_F(GateTest, SetAndGetSignal) {
    Gate gate(GateType::INPUT);
    EXPECT_FALSE(gate.getSignal());

    gate.setSignal(true);
    EXPECT_TRUE(gate.getSignal());

    gate.setSignal(false);
    EXPECT_FALSE(gate.getSignal());
}

TEST_F(GateTest, ResetSignal) {
    Gate gate(GateType::INPUT);
    gate.setSignal(true);
    EXPECT_TRUE(gate.getSignal());

    gate.reset();
    EXPECT_FALSE(gate.getSignal());
}

// Input/Output Connection Tests
TEST_F(GateTest, AddInputValid) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate andGate(GateType::AND_GATE);

    EXPECT_TRUE(andGate.addInput(&input1, 1));
    EXPECT_TRUE(andGate.addInput(&input2, 2));

    EXPECT_EQ(andGate.getInput1(), &input1);
    EXPECT_EQ(andGate.getInput2(), &input2);
}

TEST_F(GateTest, AddInputInvalid) {
    Gate gate(GateType::AND_GATE);
    Gate input(GateType::INPUT);

    // Test invalid input numbers
    EXPECT_FALSE(gate.addInput(&input, 0));
    EXPECT_FALSE(gate.addInput(&input, 3));

    // Test null gate
    EXPECT_FALSE(gate.addInput(nullptr, 1));

    // Test self-connection
    EXPECT_FALSE(gate.addInput(&gate, 1));
}

TEST_F(GateTest, RemoveInput) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate andGate(GateType::AND_GATE);

    andGate.addInput(&input1, 1);
    andGate.addInput(&input2, 2);

    andGate.removeInput(&input1);
    EXPECT_EQ(andGate.getInput1(), nullptr);
    EXPECT_EQ(andGate.getInput2(), &input2);

    andGate.removeInput(&input2);
    EXPECT_EQ(andGate.getInput2(), nullptr);
}

// Logic Gate Evaluation Tests
TEST_F(GateTest, ANDGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate andGate(GateType::AND_GATE);

    andGate.addInput(&input1, 1);
    andGate.addInput(&input2, 2);

    // Test all combinations
    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(andGate.evaluate());
    EXPECT_FALSE(andGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(andGate.evaluate());
    EXPECT_FALSE(andGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(andGate.evaluate());
    EXPECT_FALSE(andGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(andGate.evaluate());
    EXPECT_TRUE(andGate.getSignal());
}

TEST_F(GateTest, ORGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate orGate(GateType::OR_GATE);

    orGate.addInput(&input1, 1);
    orGate.addInput(&input2, 2);

    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(orGate.evaluate());
    EXPECT_FALSE(orGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(orGate.evaluate());
    EXPECT_TRUE(orGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(orGate.evaluate());
    EXPECT_TRUE(orGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(orGate.evaluate());
    EXPECT_TRUE(orGate.getSignal());
}

TEST_F(GateTest, NOTGateEvaluation) {
    Gate input(GateType::INPUT);
    Gate notGate(GateType::INVERTER);

    notGate.addInput(&input, 1);

    input.setSignal(false);
    EXPECT_TRUE(notGate.evaluate());
    EXPECT_TRUE(notGate.getSignal());

    input.setSignal(true);
    EXPECT_TRUE(notGate.evaluate());
    EXPECT_FALSE(notGate.getSignal());
}

TEST_F(GateTest, NANDGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate nandGate(GateType::NAND_GATE);

    nandGate.addInput(&input1, 1);
    nandGate.addInput(&input2, 2);

    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(nandGate.evaluate());
    EXPECT_TRUE(nandGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(nandGate.evaluate());
    EXPECT_TRUE(nandGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(nandGate.evaluate());
    EXPECT_TRUE(nandGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(nandGate.evaluate());
    EXPECT_FALSE(nandGate.getSignal());
}

TEST_F(GateTest, NORGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate norGate(GateType::NOR_GATE);

    norGate.addInput(&input1, 1);
    norGate.addInput(&input2, 2);

    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(norGate.evaluate());
    EXPECT_TRUE(norGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(norGate.evaluate());
    EXPECT_FALSE(norGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(norGate.evaluate());
    EXPECT_FALSE(norGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(norGate.evaluate());
    EXPECT_FALSE(norGate.getSignal());
}

TEST_F(GateTest, XORGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate xorGate(GateType::XOR_GATE);

    xorGate.addInput(&input1, 1);
    xorGate.addInput(&input2, 2);

    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(xorGate.evaluate());
    EXPECT_FALSE(xorGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(xorGate.evaluate());
    EXPECT_TRUE(xorGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(xorGate.evaluate());
    EXPECT_TRUE(xorGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(xorGate.evaluate());
    EXPECT_FALSE(xorGate.getSignal());
}

TEST_F(GateTest, XNORGateEvaluation) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate xnorGate(GateType::XNOR_GATE);

    xnorGate.addInput(&input1, 1);
    xnorGate.addInput(&input2, 2);

    input1.setSignal(false); input2.setSignal(false);
    EXPECT_TRUE(xnorGate.evaluate());
    EXPECT_TRUE(xnorGate.getSignal());

    input1.setSignal(true); input2.setSignal(false);
    EXPECT_TRUE(xnorGate.evaluate());
    EXPECT_FALSE(xnorGate.getSignal());

    input1.setSignal(false); input2.setSignal(true);
    EXPECT_TRUE(xnorGate.evaluate());
    EXPECT_FALSE(xnorGate.getSignal());

    input1.setSignal(true); input2.setSignal(true);
    EXPECT_TRUE(xnorGate.evaluate());
    EXPECT_TRUE(xnorGate.getSignal());
}

TEST_F(GateTest, OutputGateEvaluation) {
    Gate input(GateType::INPUT);
    Gate output(GateType::OUTPUT);

    output.addInput(&input, 1);

    input.setSignal(false);
    EXPECT_TRUE(output.evaluate());
    EXPECT_FALSE(output.getSignal());

    input.setSignal(true);
    EXPECT_TRUE(output.evaluate());
    EXPECT_TRUE(output.getSignal());
}

// Error Condition Tests
TEST_F(GateTest, EvaluateWithMissingInputs) {
    Gate andGate(GateType::AND_GATE);
    Gate input1(GateType::INPUT);

    // Missing both inputs
    EXPECT_FALSE(andGate.evaluate());

    // Missing one input
    andGate.addInput(&input1, 1);
    EXPECT_FALSE(andGate.evaluate());
}

TEST_F(GateTest, EvaluateInverterWithoutInput) {
    Gate inverter(GateType::INVERTER);
    EXPECT_FALSE(inverter.evaluate());
}

TEST_F(GateTest, EvaluateOutputWithoutInput) {
    Gate output(GateType::OUTPUT);
    EXPECT_FALSE(output.evaluate());
}

// Disconnection Tests
TEST_F(GateTest, DisconnectAll) {
    Gate input1(GateType::INPUT);
    Gate input2(GateType::INPUT);
    Gate andGate(GateType::AND_GATE);
    Gate output(GateType::OUTPUT);

    andGate.addInput(&input1, 1);
    andGate.addInput(&input2, 2);
    output.addInput(&andGate, 1);

    andGate.disconnectAll();

    EXPECT_EQ(andGate.getInput1(), nullptr);
    EXPECT_EQ(andGate.getInput2(), nullptr);
    EXPECT_EQ(output.getInput1(), nullptr);
}

TEST_F(GateTest, RemoveOutput) {
    Gate input(GateType::INPUT);
    Gate output1(GateType::OUTPUT);
    Gate output2(GateType::OUTPUT);

    output1.addInput(&input, 1);
    output2.addInput(&input, 1);

    input.removeOutput(&output1);
    EXPECT_EQ(output1.getInput1(), nullptr);
    EXPECT_EQ(output2.getInput1(), &input);

    // Test removing null output
    input.removeOutput(nullptr);
    EXPECT_EQ(output2.getInput1(), &input);
}