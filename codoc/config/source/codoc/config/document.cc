//
// codoc (c) blacktriangles 2018
//

#include "codoc/config/document.hh"

#include <cassert>
#include <fstream>

namespace codoc::config
{

//
// constructor / destructor ###################################################
//

document::document()
{
}

//
// ----------------------------------------------------------------------------
//

document::document(const std::string& config_path)
{
    bool success = load(config_path);
    assert(success);
}

//
// ----------------------------------------------------------------------------
//

document::document(std::istream& stream)
{
    bool success = load(stream);
    assert(success);
}

//
// public methods #############################################################
//

bool document::load(const std::string& config_path)
{
    std::ifstream stream(config_path, std::ios::in);
    return parse(stream);
}

//
// ----------------------------------------------------------------------------
//

bool document::parse(const std::string& data)
{
    std::stringstream stream(data, std::ios::in);
    return parse(stream);
}

//
// ----------------------------------------------------------------------------
//

bool document::parse(std::istream& stream)
{
    YAML::Parser parser(stream);
    parser.GetNextDocument(m_document);
}

//
// ############################################################################
//

}
