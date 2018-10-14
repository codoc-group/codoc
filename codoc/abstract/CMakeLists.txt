#
# codoc blacktriangles (c) 2018 ###############################################
#

#
# configuration ###############################################################
#

set(target abstract)

# Header and Source Files -----------------------------------------------------
set(include_path ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(source_path ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(headers
    ${include_path}/codoc/abstract.hh
    ${include_path}/codoc/abstract/document.hh
)

set(sources
    ${source_path}/codoc/abstract.cc
    ${source_path}/codoc/abstract/document.cc
)

#
# Library name and options ####################################################
#

message(STATUS "Lib ${target}")

# Set API export file and macro
string(MAKE_C_IDENTIFIER ${target} target_id)
string(TOUPPER ${target_id} target_id)

#
# Library #####################################################################
#

add_library(${target} ${header} ${sources})
add_library(${META_PROJECT_NAME}::${target} ALIAS ${target})

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

    PUBLIC
        ${DEFAULT_INCLUDE_DIRECTORIES}
        ${include_path}

    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/source>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# link libraries --------------------------------------------------------------
target_link_libraries(${target}
    PRIVATE

    PUBLIC
        ${DEFAULT_LIBRARIES}

    INTERFACE
)

# compile definitions ---------------------------------------------------------
target_compile_definitions(${target}
    PRIVATE

    PUBLIC
        $<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:${target_id}_STATIC_DEFINE>
        ${DEFAULT_COMPILE_DEFINITIONS}

    INTERFACE
)

# compile options -------------------------------------------------------------
target_compile_options(${target}
    PRIVATE

    PUBLIC
        ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)

# link options ----------------------------------------------------------------
target_link_libraries(${target}
    PRIVATE

    PUBLIC
        ${DEFAULT_LINKER_OPTIONS}

    INTERFACE
)

#
# Deployment ##################################################################
#
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN}    COMPONENT runtime
    LIBRARY DESTINATION ${INSTALL_SHARED} COMPONENT runtime
    ARCHIVE DESTINATION ${INSTALL_LIB}    COMPONENT dev
)

# header files ----------------------------------------------------------------
install(DIRECTORY
    ${include_path}/codoc DESTINATION ${INSTALL_INCLUDE}
    COMPONENT dev
)
