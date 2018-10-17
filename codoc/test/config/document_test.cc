//
// codoc (c) 2018 blacktriangles
//

#include <gtest/gtest.h>
#include <fstream>

TEST(document_test, true_is_true)
{
    std::ifstream stream("config_test.yml");
    ASSERT_TRUE(stream.good());
}
