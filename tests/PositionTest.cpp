#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Navigator/Position.h"

using testing::Eq;

TEST(position, distance)
{
    Position pos1 = Position(51.5007, 0.1246);
    Position pos2 = Position(40.6892, 74.0445);

    double result = abs(pos1 - pos2);

    EXPECT_EQ(5574.840456848555, result);
}

