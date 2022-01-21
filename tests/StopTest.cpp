#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Stop.h"

using testing::Eq;

TEST(stop, loading)
{
   Stop stop;
   Position pos;

   stop.loadFromCsv("code,name,zone,12.3,45.5");
   pos = Position(12.3, 45.6);

   EXPECT_EQ("code", stop.getCode());
   EXPECT_EQ("name", stop.getName());
   EXPECT_EQ("zone", stop.getZone());
   EXPECT_EQ(pos, stop.getPosition());
}