#
# codoc
# blacktriangles (c) 2018
#

#
# External dependencies #######################################################
#

#
# Library name and options ####################################################
#

set(target test)

message(STATUS "Test ${target}")

# Set API export file and macro -----------------------------------------------
string(MAKE_C_IDENTIFIER ${target} target_id)
string(TOUPPER ${target_id} target_id)

# setup custom test target ----------------------------------------------------
add_custom_target(codoc-test)
set_target_properties(codoc-test PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

# add test without ctest ------------------------------------------------------
#function(add_test_without_ctest target)
#    add_subdirectory(${target})
#    
#    if(NOT TARGET ${target}-test)
#        return()
#    endif()
#    
#    add_dependencies(codoc-test ${target}-test)
#    add_custom_command(TARGET codoc-test POST_BUILD 
#        COMMAND $<TARGET_FILE:${target}> --gtest_output=xml:gtests-${target}.xml)
#endfunction()

# add test subfolders ---------------------------------------------------------
add_subdirectory( abstract )
add_subdirectory( parse )
