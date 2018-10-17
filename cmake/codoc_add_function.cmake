#
# codoc (c) blacktriangles 2018 ###############################################
#

function(codoc_add_function)
    # parse arguments ---------------------------------------------------------
    set(options)

    set(oneValueArgs 
        NAME 
        TYPE
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

    set(include_path ${CMAKE_CURRENT_SOURCE_DIR}/${ARG_INCLUDE_PATH})
    set(source_path ${CMAKE_CURRENT_SOURCE_DIR}/${ARG_SOURCE_PATH})

    set(headers "")
    foreach(header ${ARG_HEADERS})
        LIST(APPEND headers "${include_path}/${header}")
    endforeach()

    set(sources "")
    foreach(source ${ARG_SOURCES})
        LIST(APPEND sources "${source_path}/${source}")
    endforeach()

    # copy data ---------------------------------------------------------------
    foreach(datum ${ARG_DATA})
        configure_file("${CMAKE_CURRENT_SOURCE_DIR}/${datum}" "${CMAKE_CURRENT_BINARY_DIR}/${datum}" COPYONLY)
    endforeach()

    # build library -----------------------------------------------------------
    set(target ${ARG_NAME})
    message(STATUS "Building ${ARG_TYPE} ${target}")

    if(${ARG_TYPE} STREQUAL "Library")
        add_library(${target} ${headers} ${sources})
        add_library(${META_PROJECT_NAME}::${target} ALIAS ${target})
    elseif(${ARG_TYPE} STREQUAL "Executable")
        add_executable(${target} ${headers} ${sources})
        add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})
    elseif(${ARG_TYPE} STREQUAL "Test")
        add_executable(${target} ${headers} ${sources})
        add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})
        add_test(NAME ${META_PROJECT_NAME}::${target} COMMAND ${target})
    endif()
        

    # properties --------------------------------------------------------------
    set_target_properties(${target}
        PROPERTIES
            ${DEFAULT_PROJECT_OPTIONS}
            FOLDER "${IDE_FOLDER}"
            VERSION ${META_VERSION}
            SOVERSION ${META_VERSION_MAJOR}
    )

    # include directories -----------------------------------------------------
    target_include_directories(${target}
        PRIVATE
            ${source_path}

        PUBLIC
            ${include_path}

        INTERFACE
            $<BUILD_INTERFACE:${ARG_SOURCE_PATH}>
            $<BUILD_INTERFACE:${ARG_INCLUDE_PATH}>
            $<INSTALL_INTERFACE:include>
    )

    # link libraries --------------------------------------------------------------
    target_link_libraries(${target}
        PRIVATE
            ${ARG_PRIVATE_DEPS}
    
        PUBLIC
            ${DEFAULT_LIBRARIES}
            ${ARG_PUBLIC_DEPS}
    )
    
    # compile definitions ---------------------------------------------------------
    target_compile_definitions(${target}
        PUBLIC
            $<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:${target_id}_STATIC_DEFINE>
            ${DEFAULT_COMPILE_DEFINITIONS}
    )
    
    # compile options -------------------------------------------------------------
    target_compile_options(${target}
        PUBLIC
            ${DEFAULT_COMPILE_OPTIONS}
    )
    
    # link options ----------------------------------------------------------------
    target_link_libraries(${target}
        PUBLIC
            ${DEFAULT_LINKER_OPTIONS}
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
endfunction()
