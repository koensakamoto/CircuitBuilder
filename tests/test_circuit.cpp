#include <gtest/gtest.h>
#include "../Circuit.h"
#include "../Gate.h"
#include <QApplication>

class CircuitTest : public ::testing::Test {
protected:
    void SetUp() override {
        circuit = new Circuit();
    }

    void TearDown() override {
        delete circuit;
    }

    Circuit* circuit;
};

TEST_F(CircuitTest, InitialStateTest) {
    EXPECT_NE(circuit, nullptr);
    EXPECT_EQ(circuit->getGates().size(), 0);
}

TEST_F(CircuitTest, AddGateTest) {
    Gate* andGate = new Gate(GateType::AND, QPointF(100, 100));
    circuit->addGate(andGate);
    EXPECT_EQ(circuit->getGates().size(), 1);
}

TEST_F(CircuitTest, RemoveGateTest) {
    Gate* orGate = new Gate(GateType::OR, QPointF(200, 200));
    circuit->addGate(orGate);
    EXPECT_EQ(circuit->getGates().size(), 1);

    circuit->removeGate(orGate);
    EXPECT_EQ(circuit->getGates().size(), 0);
}

TEST_F(CircuitTest, ConnectGatesTest) {
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 50));

    circuit->addGate(input1);
    circuit->addGate(input2);
    circuit->addGate(andGate);

    circuit->connectGates(input1, andGate, 0);
    circuit->connectGates(input2, andGate, 1);

    EXPECT_EQ(circuit->getConnections().size(), 2);
}

TEST_F(CircuitTest, CircuitEvaluationANDTest) {
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

    // Test AND truth table
    input1->setState(false);
    input2->setState(false);
    circuit->evaluate();
    EXPECT_FALSE(output->getState());

    input1->setState(true);
    input2->setState(false);
    circuit->evaluate();
    EXPECT_FALSE(output->getState());

    input1->setState(false);
    input2->setState(true);
    circuit->evaluate();
    EXPECT_FALSE(output->getState());

    input1->setState(true);
    input2->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState());
}

TEST_F(CircuitTest, CircuitEvaluationORTest) {
    Gate* input1 = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* input2 = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* orGate = new Gate(GateType::OR, QPointF(200, 50));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(400, 50));

    circuit->addGate(input1);
    circuit->addGate(input2);
    circuit->addGate(orGate);
    circuit->addGate(output);

    circuit->connectGates(input1, orGate, 0);
    circuit->connectGates(input2, orGate, 1);
    circuit->connectGates(orGate, output, 0);

    // Test OR truth table
    input1->setState(false);
    input2->setState(false);
    circuit->evaluate();
    EXPECT_FALSE(output->getState());

    input1->setState(true);
    input2->setState(false);
    circuit->evaluate();
    EXPECT_TRUE(output->getState());

    input1->setState(false);
    input2->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState());

    input1->setState(true);
    input2->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState());
}

TEST_F(CircuitTest, CircuitEvaluationNOTTest) {
    Gate* input = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* notGate = new Gate(GateType::NOT, QPointF(200, 0));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(400, 0));

    circuit->addGate(input);
    circuit->addGate(notGate);
    circuit->addGate(output);

    circuit->connectGates(input, notGate, 0);
    circuit->connectGates(notGate, output, 0);

    // Test NOT gate
    input->setState(false);
    circuit->evaluate();
    EXPECT_TRUE(output->getState());

    input->setState(true);
    circuit->evaluate();
    EXPECT_FALSE(output->getState());
}

TEST_F(CircuitTest, ComplexCircuitTest) {
    // Create a more complex circuit: (A AND B) OR (NOT C)
    Gate* inputA = new Gate(GateType::INPUT, QPointF(0, 0));
    Gate* inputB = new Gate(GateType::INPUT, QPointF(0, 100));
    Gate* inputC = new Gate(GateType::INPUT, QPointF(0, 200));
    Gate* andGate = new Gate(GateType::AND, QPointF(200, 50));
    Gate* notGate = new Gate(GateType::NOT, QPointF(200, 200));
    Gate* orGate = new Gate(GateType::OR, QPointF(400, 125));
    Gate* output = new Gate(GateType::OUTPUT, QPointF(600, 125));

    circuit->addGate(inputA);
    circuit->addGate(inputB);
    circuit->addGate(inputC);
    circuit->addGate(andGate);
    circuit->addGate(notGate);
    circuit->addGate(orGate);
    circuit->addGate(output);

    circuit->connectGates(inputA, andGate, 0);
    circuit->connectGates(inputB, andGate, 1);
    circuit->connectGates(inputC, notGate, 0);
    circuit->connectGates(andGate, orGate, 0);
    circuit->connectGates(notGate, orGate, 1);
    circuit->connectGates(orGate, output, 0);

    // Test some combinations
    inputA->setState(true);
    inputB->setState(true);
    inputC->setState(true);
    circuit->evaluate();
    EXPECT_TRUE(output->getState()); // (1 AND 1) OR (NOT 1) = 1 OR 0 = 1

    inputA->setState(false);
    inputB->setState(false);
    inputC->setState(true);
    circuit->evaluate();
    EXPECT_FALSE(output->getState()); // (0 AND 0) OR (NOT 1) = 0 OR 0 = 0

    inputA->setState(false);
    inputB->setState(true);
    inputC->setState(false);
    circuit->evaluate();
    EXPECT_TRUE(output->getState()); // (0 AND 1) OR (NOT 0) = 0 OR 1 = 1
}