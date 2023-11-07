#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../cppaudit/gtest_ext.h"

using ::testing::HasSubstr;

TEST(Driver, OutputShouldHaveSecretKeyFromReadMe) {
  ASSERT_EXECTHAT("main", "", HasSubstr("TUFFY121L")) << "Missing secret key. Make sure to read the README with your lab partner!";  
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
