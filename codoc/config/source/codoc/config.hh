//
// codoc (c) blacktriangles 2018
//

#pragma once

#include <istream.h>

namespace codoc
{

//
// this class is responsible for serializing and storing configuration values
// for a codoc run
//
class config
{
public: // types --------------------------------------------------------------

    using cpptoml::table section;

public: // constructor / destructor -------------------------------------------
    
    //
    // default constructor
    //
    config();

    //
    // constructor taking a path to the config file.
    //
    config(const std::string& config_path);

    //
    // constructor taking an istream to the config data
    //
    config(std::istream& data);

    //
    // copy constructor
    //
    config(const config& copy) = default;

    //
    // move constructor
    //
    config(config&& move) = default;

    //
    // default destructor
    //
    virtual ~config() = default;

public: // public methods -----------------------------------------------------

    //
    // loads a config from the specified path
    //
    bool load(const std::string& config_path);

    //
    // loada a config from the specified istream
    //
    bool load(const std::istream& stream);

public: // operator overrides -------------------------------------------------

    //
    // assignment operator
    //
    config& operator(const config& copy) = default;

    //
    // move operator
    //
    config& operator(config&& move) = default;

private: // members -----------------------------------------------------------

};

}
