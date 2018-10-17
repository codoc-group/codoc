//
// codoc (c) 2018 blacktriangles
//

#include "codoc/config/document.hh"

#include <gtest/gtest.h>
#include <fstream>

TEST(document_test, open_by_string)
{
    codoc::config::document doc("config_test.yml");
    ASSERT_NE(doc.get_root().IsSequence(), true);

}
