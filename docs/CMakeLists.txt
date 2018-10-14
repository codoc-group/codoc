#
# codoc blacktriangles (c) 2018 ###############################################
#

#
# config ######################################################################
#

set(target parse-test)

set(headers
)

set(sources
    parse_test.cc
)

set(deps
    parse
)

# 
# Documentation ###############################################################
# 

if(NOT OPTION_BUILD_DOCS)
    return()
endif()

add_custom_target(docs)


# docs subdirectories ---------------------------------------------------------

#add_subdirectory(api-docs)
#add_subdirectory(manual)
