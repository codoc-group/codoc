#
# codoc
# blacktriangles (c) 2018
#

#
# configuration ###############################################################
#

set(target test)


#
# Library name and options ####################################################
#

message(STATUS "Test ${target}")

# Set API export file and macro -----------------------------------------------
string(MAKE_C_IDENTIFIER ${target} target_id)
string(TOUPPER ${target_id} target_id)

# setup custom test target ----------------------------------------------------
add_custom_target(codoc-test)
set_target_properties(codoc-test PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)

# add test subfolders ---------------------------------------------------------
add_subdirectory( abstract )
add_subdirectory( parse )
