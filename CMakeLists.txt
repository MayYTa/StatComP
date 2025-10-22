cmake_minimum_required(VERSION 3.30)

project(StatComp)

set(A_TAG "4.13.2")
set(BASE_DIR "/home/mayta/Apps/antlr4/runtime")
set(ANTLR_DIR "/home/mayta/Desktop/CompilersTheory/")
set(CMAKE_MODULE_PATH "${BASE_DIR}/Cpp/cmake/")
set(ANTLR_EXECUTABLE "${ANTLR_DIR}antlr-${A_TAG}-complete.jar")
set(PROG_INCLUDE_DIR "${BASE_DIR}/Cpp/run/usr/local/include/antlr4-runtime/")
set(PROG_LIB_DIR "${BASE_DIR}/Cpp/run/usr/local/lib/")

if(NOT EXISTS "${ANTLR_EXECUTABLE}")
  message(FATAL_ERROR "Couldn't find ${ANTLR_EXECUTABLE}")
endif()

find_package(ANTLR)

message(STATUS "Found ANtlr: ${A_TAG}")
message(STATUS "Antlr gen dir: ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR} ")

file(GLOB SOURCES "*.cpp")
file(GLOB GFOURS "*.g4")

antlr_target(${PROJECT_NAME} ${GFOURS} LEXER PARSER VISITOR)

add_executable(${PROJECT_NAME} ${SOURCES} ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS})
target_link_directories(${PROJECT_NAME} PRIVATE ${PROG_LIB_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime)
target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${PROG_INCLUDE_DIR}
  ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)




