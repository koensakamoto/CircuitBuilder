#include <gtest/gtest.h>
#include "../Gate.h"

class SimpleTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SimpleTest, BasicGateCreation) {
    Gate gate;
    EXPECT_TRUE(true); // Basic test that should always pass
}

TEST_F(SimpleTest, GateTypeCreation) {
    Gate andGate(GateType::AND_GATE);
    EXPECT_EQ(andGate.getType(), GateType::AND_GATE);
}

TEST_F(SimpleTest, DifferentGateTypes) {
    Gate orGate(GateType::OR_GATE);
    Gate inverter(GateType::INVERTER);

    EXPECT_EQ(orGate.getType(), GateType::OR_GATE);
    EXPECT_EQ(inverter.getType(), GateType::INVERTER);
}