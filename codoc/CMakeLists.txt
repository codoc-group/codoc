#
# codoc
# blacktriangles (c) 2018
#

#
# Configuration for all sub-projects ##########################################
#

# Generation version-header
configure_file(version.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME}/${META_PROJECT_NAME}-version.h)

#
# Sub Projects ################################################################
#

# Libraries -------------------------------------------------------------------
set(IDE_FOLDER "")
add_subdirectory(abstract)
add_subdirectory(parse)

# Tests -----------------------------------------------------------------------
if(OPTION_BUILD_TESTS AND NOT MINGW)
    set(IDE_FOLDER "Tests")
    add_subdirectory(test)
endif()

#
# Deployment ##################################################################
#

# Deploy generated headers
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/include/${META_PROJECT_NAME} DESTINATION include COMPONENT dev)
