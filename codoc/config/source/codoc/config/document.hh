//
// codoc (c) blacktriangles 2018
//

#pragma once

#include "codoc/config.hh"

#include <yaml-cpp/yaml.h>

#include <istream>

namespace codoc::config
{

//
// this class is responsible for serializing and storing configuration values
// for a codoc run
//
class document 
{
public: // types --------------------------------------------------------------

    using section = YAML::Node;

public: // constructor / destructor -------------------------------------------
    
    //
    // default constructor
    //
    document();

    //
    // constructor taking a string containing yaml data to parse
    //
    document(const std::string& data);

    //
    // constructor taking an istream to the config data
    //
    document(std::istream& data);

    //
    // copy constructor
    //
    document(const document& copy) = default;

    //
    // move constructor
    //
    document(document&& move) = default;

    //
    // default destructor
    //
    virtual ~document() = default;

public: // public methods -----------------------------------------------------

    //
    // loads a config from the specified path
    //
    bool load(const std::string& config_path);

    //
    // parses a string
    //
    bool parse(const std::string& data);

    //
    // loada a config from the specified istream
    //
    bool parse(std::istream& stream);

    //
    // gets a configuration section by key.  if the key does not exist,
    // this will return a nullptr
    //
    section* get_section(const std::string& key) const;

public: // operator overrides -------------------------------------------------

    //
    // assignment operator
    //
    document& operator=(const document& copy) = default;

    //
    // move operator
    //
    document& operator=(document&& move) = default;

private: // members -----------------------------------------------------------

    //
    // The root sections of the document
    //
    std::vector<section> m_sections;

};

} //namespace codoc::config
