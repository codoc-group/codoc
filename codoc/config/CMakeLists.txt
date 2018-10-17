#
# codoc (c) blacktriangles 2018 ###############################################
#

codoc_add_library(
    NAME config
    INCLUDE_PATH include
    SOURCE_PATH source
    HEADERS
        codoc/config/document.hh

    SOURCES
        document.cc

    PUBLIC_DEPS
        absl::base
        yaml-cpp
)
