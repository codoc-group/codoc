#
# codoc (c) blacktriangles 2018 ###############################################
#

include(codoc_add_function)

function(codoc_add_executable)
    # parse arguments ---------------------------------------------------------
    set(options)

    set(oneValueArgs 
        NAME 
        INCLUDE_PATH 
        SOURCE_PATH
    )

    set(multiValueArgs 
        HEADERS 
        SOURCES 
        PUBLIC_DEPS 
        PRIVATE_DEPS 
        DATA
    )

    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    codoc_add_function(
        NAME ${ARG_NAME}
        TYPE Executable
        INCLUDE_PATH ${ARG_INCLUDE_PATH}
        SOURCE_PATH ${ARG_SOURCE_PATH}
        HEADERS ${ARG_HEADERS}
        SOURCES ${ARG_SOURCES}
        PUBLIC_DEPS ${ARG_PUBLIC_DEPS}
        PRIVATE_DEPS ${ARG_PRIVATE_DEPS}
        DATA ${ARG_DATA}
    )
endfunction()
