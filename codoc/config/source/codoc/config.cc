//
// codoc (c) blacktriangles 2018
//

#include "codoc/config.hh"

#include <cassert>
#include <fstream>

namespace codoc
{

//
// constructor / destructor ###################################################
//

config::config()
{
}

//
// ----------------------------------------------------------------------------
//

config::config(const std::string& config_path)
{
    bool success = load(config_path);
    assert(success);
}

//
// ----------------------------------------------------------------------------
//

config::config(std::istream& stream)
{
    bool success = load(stream);
    assert(success);
}

//
// public methods #############################################################
//

bool config::load(const std::string& config_path)
{
    std::ifstream stream(config_path, std::ios::in);
    return load(stream);
}

//
// ----------------------------------------------------------------------------
//

bool config::load(std::istream& /*stream*/)
{
    return false;
}

//
// ############################################################################
//

}
