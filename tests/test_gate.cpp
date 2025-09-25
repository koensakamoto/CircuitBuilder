#include <gtest/gtest.h>
#include "../Gate.h"
#include <QPointF>

class GateTest : public ::testing::Test {
protected:
    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(GateTest, GateCreationTest) {
    Gate* andGate = new Gate(GateType::AND, QPointF(100, 100));
    EXPECT_NE(andGate, nullptr);
    EXPECT_EQ(andGate->getType(), GateType::AND);
    EXPECT_EQ(andGate->getPosition(), QPointF(100, 100));
    delete andGate;
}

TEST_F(GateTest, GateStateTest) {
    Gate* inputGate = new Gate(GateType::INPUT, QPointF(0, 0));

    inputGate->setState(false);
    EXPECT_FALSE(inputGate->getState());

    inputGate->setState(true);
    EXPECT_TRUE(inputGate->getState());

    delete inputGate;
}

TEST_F(GateTest, ANDGateLogicTest) {
    Gate* andGate = new Gate(GateType::AND, QPointF(0, 0));

    // Test all combinations for AND gate
    andGate->setInput(0, false);
    andGate->setInput(1, false);
    andGate->evaluate();
    EXPECT_FALSE(andGate->getOutput());

    andGate->setInput(0, true);
    andGate->setInput(1, false);
    andGate->evaluate();
    EXPECT_FALSE(andGate->getOutput());

    andGate->setInput(0, false);
    andGate->setInput(1, true);
    andGate->evaluate();
    EXPECT_FALSE(andGate->getOutput());

    andGate->setInput(0, true);
    andGate->setInput(1, true);
    andGate->evaluate();
    EXPECT_TRUE(andGate->getOutput());

    delete andGate;
}

TEST_F(GateTest, ORGateLogicTest) {
    Gate* orGate = new Gate(GateType::OR, QPointF(0, 0));

    // Test all combinations for OR gate
    orGate->setInput(0, false);
    orGate->setInput(1, false);
    orGate->evaluate();
    EXPECT_FALSE(orGate->getOutput());

    orGate->setInput(0, true);
    orGate->setInput(1, false);
    orGate->evaluate();
    EXPECT_TRUE(orGate->getOutput());

    orGate->setInput(0, false);
    orGate->setInput(1, true);
    orGate->evaluate();
    EXPECT_TRUE(orGate->getOutput());

    orGate->setInput(0, true);
    orGate->setInput(1, true);
    orGate->evaluate();
    EXPECT_TRUE(orGate->getOutput());

    delete orGate;
}

TEST_F(GateTest, NOTGateLogicTest) {
    Gate* notGate = new Gate(GateType::NOT, QPointF(0, 0));

    // Test NOT gate
    notGate->setInput(0, false);
    notGate->evaluate();
    EXPECT_TRUE(notGate->getOutput());

    notGate->setInput(0, true);
    notGate->evaluate();
    EXPECT_FALSE(notGate->getOutput());

    delete notGate;
}

TEST_F(GateTest, NANDGateLogicTest) {
    Gate* nandGate = new Gate(GateType::NAND, QPointF(0, 0));

    // Test all combinations for NAND gate
    nandGate->setInput(0, false);
    nandGate->setInput(1, false);
    nandGate->evaluate();
    EXPECT_TRUE(nandGate->getOutput());

    nandGate->setInput(0, true);
    nandGate->setInput(1, false);
    nandGate->evaluate();
    EXPECT_TRUE(nandGate->getOutput());

    nandGate->setInput(0, false);
    nandGate->setInput(1, true);
    nandGate->evaluate();
    EXPECT_TRUE(nandGate->getOutput());

    nandGate->setInput(0, true);
    nandGate->setInput(1, true);
    nandGate->evaluate();
    EXPECT_FALSE(nandGate->getOutput());

    delete nandGate;
}

TEST_F(GateTest, NORGateLogicTest) {
    Gate* norGate = new Gate(GateType::NOR, QPointF(0, 0));

    // Test all combinations for NOR gate
    norGate->setInput(0, false);
    norGate->setInput(1, false);
    norGate->evaluate();
    EXPECT_TRUE(norGate->getOutput());

    norGate->setInput(0, true);
    norGate->setInput(1, false);
    norGate->evaluate();
    EXPECT_FALSE(norGate->getOutput());

    norGate->setInput(0, false);
    norGate->setInput(1, true);
    norGate->evaluate();
    EXPECT_FALSE(norGate->getOutput());

    norGate->setInput(0, true);
    norGate->setInput(1, true);
    norGate->evaluate();
    EXPECT_FALSE(norGate->getOutput());

    delete norGate;
}

TEST_F(GateTest, XORGateLogicTest) {
    Gate* xorGate = new Gate(GateType::XOR, QPointF(0, 0));

    // Test all combinations for XOR gate
    xorGate->setInput(0, false);
    xorGate->setInput(1, false);
    xorGate->evaluate();
    EXPECT_FALSE(xorGate->getOutput());

    xorGate->setInput(0, true);
    xorGate->setInput(1, false);
    xorGate->evaluate();
    EXPECT_TRUE(xorGate->getOutput());

    xorGate->setInput(0, false);
    xorGate->setInput(1, true);
    xorGate->evaluate();
    EXPECT_TRUE(xorGate->getOutput());

    xorGate->setInput(0, true);
    xorGate->setInput(1, true);
    xorGate->evaluate();
    EXPECT_FALSE(xorGate->getOutput());

    delete xorGate;
}

TEST_F(GateTest, XNORGateLogicTest) {
    Gate* xnorGate = new Gate(GateType::XNOR, QPointF(0, 0));

    // Test all combinations for XNOR gate
    xnorGate->setInput(0, false);
    xnorGate->setInput(1, false);
    xnorGate->evaluate();
    EXPECT_TRUE(xnorGate->getOutput());

    xnorGate->setInput(0, true);
    xnorGate->setInput(1, false);
    xnorGate->evaluate();
    EXPECT_FALSE(xnorGate->getOutput());

    xnorGate->setInput(0, false);
    xnorGate->setInput(1, true);
    xnorGate->evaluate();
    EXPECT_FALSE(xnorGate->getOutput());

    xnorGate->setInput(0, true);
    xnorGate->setInput(1, true);
    xnorGate->evaluate();
    EXPECT_TRUE(xnorGate->getOutput());

    delete xnorGate;
}

TEST_F(GateTest, GatePositionTest) {
    Gate* gate = new Gate(GateType::AND, QPointF(150, 250));

    EXPECT_EQ(gate->getPosition(), QPointF(150, 250));

    gate->setPosition(QPointF(300, 400));
    EXPECT_EQ(gate->getPosition(), QPointF(300, 400));

    delete gate;
}