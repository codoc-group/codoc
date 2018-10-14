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

set(target abstract-test)

message(STATUS "Test ${target}")

# Set API export file and macro
string(MAKE_C_IDENTIFIER ${target} target_id)
string(TOUPPER ${target_id} target_id)

#
# Header and Source Files #####################################################
#
set(headers
)

set(sources
    document_test.cc
)

#
# Library #####################################################################
#

add_executable(${target} ${header} ${sources})
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})
add_test(NAME ${target} COMMAND ${target})

# properties ------------------------------------------------------------------
set_target_properties(${target}
    PROPERTIES
        ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
    VERSION ${META_VERSION}
    SOVERSION ${META_VERSION_MAJOR}
)

# include directories ---------------------------------------------------------
target_include_directories(${target}
    PRIVATE
        ${DEFAULT_INCLUDE_DIRECTORIES}
        ${include_path}
)

# link libraries --------------------------------------------------------------
target_link_libraries(${target}
    PRIVATE
        gtest-dev
        gtest_main
        abstract
)

# compile definitions ---------------------------------------------------------
target_compile_definitions(${target}
    PRIVATE
        $<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:${target_id}_STATIC_DEFINE>
        ${DEFAULT_COMPILE_DEFINITIONS}
)

# compile options -------------------------------------------------------------
target_compile_options(${target}
    PRIVATE
        ${DEFAULT_COMPILE_OPTIONS}
)

# link options ----------------------------------------------------------------
target_link_libraries(${target}
    PRIVATE
        ${DEFAULT_LINKER_OPTIONS}
)

