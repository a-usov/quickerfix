#include "quickerfix/Hello.h"
#include <gtest/gtest.h>

TEST(HelloTest, HelloTest) { EXPECT_EQ("Hello, World!", qf::hello()); }
