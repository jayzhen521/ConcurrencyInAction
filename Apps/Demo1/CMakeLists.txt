get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
get_filename_component(ProjectPath ${CMAKE_CURRENT_LIST_DIR} DIRECTORY)
get_filename_component(ParentDir ${ProjectPath} NAME)

string(REPLACE " " "_" ProjectId ${ProjectId})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

if(MSVC)
    file(GLOB INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/${ProjectId}/*h)
    file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp)
    add_executable(
        ${ProjectId}
        ${SRC_FILES} ${INCLUDE_FILES}
    )
else()
endif()

target_include_directories(
    ${ProjectId}
    PRIVATE
)

target_link_libraries(${ProjectId}
    PRIVATE
)

if(MSVC)
    set_property(TARGET ${ProjectId} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

    set_property(TARGET ${ProjectId} PROPERTY FOLDER ${ParentDir}) 
endif()

target_compile_features(${ProjectId} PRIVATE cxx_std_17)