//
// codoc (c) blacktriangles 2018
//

#pragma once

namespace codoc
{

//
// this class is responsible for serializing and storing configuration values
// for a codoc run
//
class config
{

public: // constructor / destructor -------------------------------------------
    
    //
    // default constructor
    //
    config();

    //
    // constructor taking a path to the config file
    //
    config(const std::string& config_path);

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
