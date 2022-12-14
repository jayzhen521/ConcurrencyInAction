cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

get_filename_component(SolutionName ${CMAKE_SOURCE_DIR} NAME)

project(${SolutionName} LANGUAGES C CXX)

set(Dependency ${CMAKE_SOURCE_DIR}/../Dependency/)

# find_include and find_library
find_path(GLM_INCLUDE_DIR
    glm/matrix.hpp
    HINTS
        ${Dependency}/glm/include
)

find_path(GLOG_INCLUDE_DIR
    glog/logging.h
    HINTS
        ${Dependency}/glog/include
)

find_path(GLOG_LIBRARY_DIR
    glog.lib
    HINTS
        ${Dependency}/glog/lib
)

# end find_include and find_library

#macro
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
#end macro

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "")

add_definitions(-DNOMINMAX)

add_subdirectory(Apps)

add_subdirectory(Logic)


#MESSAGE( STATUS "this var key = ${ProjectX}.")
