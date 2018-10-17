//
// codoc (c) blacktriangles 2018
//

#pragma once

#include <yaml-cpp/yaml.h>
#include <istream>

namespace codoc::config
{

//
// each section within the document is a YAML::Node
//
using section = YAML::Node;

//
// this class is responsible for serializing and storing configuration values
// for a codoc run
//
class document final
{
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
    ~document() = default;

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
    // get the root section of this document
    //
    const section& get_root() const;

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
    section m_root;

};

} //namespace codoc::config