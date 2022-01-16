#define APPROVALS_GOOGLETEST

#include "quickerfix/FixConfigParser.h"
#include <ApprovalTests.hpp>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FixConfigParser, testNonExistingFile) {
  ::testing::internal::CaptureStdout();

  ASSERT_EQ(qf::load_document("non-existing-file.xml"), std::nullopt);

  const auto log_output = ::testing::internal::GetCapturedStdout();
  ASSERT_THAT(log_output, ::testing::HasSubstr("Could not parse FIX configuration file, error: File was not found"));
}

TEST(FixConfigParser, testFIX42) {
  const auto fix = qf::load_document("../../spec/FIX42.xml");
  ASSERT_NE(fix, std::nullopt);

  ApprovalTests::Approvals::verify(fix.value());
}
