cmake_minimum_required(VERSION 3.30)

set(CMAKE_BUILD_TYPE Debug)
project(StatComp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================================================
# 1. CONFIGURACIÓN DE RUTAS Y ANTLR JAR
# =========================================================
set(MY_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../..")

# [WIN32] Tu configuración específica (MSYS2 / DevTools)
if(WIN32)
    # Ruta directa a tu JAR para no descargarlo cada vez
    set(LOCAL_ANTLR_JAR "C:/Users/jeydi/DevTools/antlr-4.13.2-complete.jar")
    if(EXISTS "${LOCAL_ANTLR_JAR}")
        set(ANTLR_EXECUTABLE "${LOCAL_ANTLR_JAR}")
    else()
        set(ANTLR_EXECUTABLE "${MY_BASE_DIR}/antlr-4.13.2-complete.jar")
    endif()
else()
    # [LINUX] Configuración de tu compañero
    set(ANTLR_EXECUTABLE "${MY_BASE_DIR}/antlr-4.13.2-complete.jar")
endif()

# Buscamos el header de ANTLR (Combinamos rutas de Linux y Windows/MSYS2)
find_path(ANTLR_INCLUDE_DIR
  NAMES antlr4-runtime.h
  PATHS 
    /usr/include 
    /usr/local/include 
    /usr/include/antlr4-runtime 
    /usr/local/include/antlr4-runtime
    "C:/msys64/ucrt64/include/antlr4-runtime"  # [WIN32] Tu ruta MSYS2
    "C:/Users/jeydi/DevTools/antlr4-runtime/include/antlr4-runtime" # [WIN32] Tu ruta backup
)

if(NOT ANTLR_INCLUDE_DIR)
  message(FATAL_ERROR "Could not find antlr4-runtime.h. Install ANTLR runtime.")
endif()

list(APPEND CMAKE_MODULE_PATH ${MY_BASE_DIR})

# Descarga del JAR (Solo si no existe en la ruta definida arriba)
if(NOT EXISTS "${ANTLR_EXECUTABLE}")
    message(STATUS "Couldn't find: ${ANTLR_EXECUTABLE}")
    message(STATUS "Trying to download it...")
    file(DOWNLOAD
    "https://www.antlr.org/download/antlr-4.13.2-complete.jar"
    "${ANTLR_EXECUTABLE}"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

# Descarga de FindANTLR.cmake (Lógica compartida)
if(NOT EXISTS "${MY_BASE_DIR}/FindANTLR.cmake")
    message(STATUS "Couldn't find: FindANTLR.cmake")
    message(STATUS "Trying to download it.")
    set(URL1 "https://raw.githubusercontent.com/antlr/antlr4/")
    set(URL2 "master/runtime/Cpp/cmake/FindANTLR.cmake") 
    file(DOWNLOAD
    "${URL1}${URL2}"
    "${MY_BASE_DIR}/FindANTLR.cmake"
    STATUS DOWNLOAD_STATUS TIMEOUT 60)
endif()

find_package(ANTLR)
message(STATUS "Found ANTLR: ${ANTLR_VERSION}")

file(GLOB GFOURS "*.g4")

# =========================================================
# 3. GENERACIÓN DE CÓDIGO ANTLR
# =========================================================
# Intentamos usar la macro estándar. Si falla (común en Windows), usamos fallback.
if(ANTLR_FOUND)
    antlr_target(${PROJECT_NAME} ${GFOURS} LEXER PARSER VISITOR)
else()
    # Fallback manual por si FindANTLR falla en tu entorno
    message(STATUS "ANTLR package not found via CMake, using manual command.")
    set(ANTLR_${PROJECT_NAME}_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
    file(MAKE_DIRECTORY ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR})
    set(ANTLR_${PROJECT_NAME}_CXX_OUTPUTS 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompLexer.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompParser.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompBaseVisitor.cpp" 
        "${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}/StatCompVisitor.cpp"
    )
    add_custom_command(OUTPUT ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS}
        COMMAND java -jar ${ANTLR_EXECUTABLE} -Dlanguage=Cpp -no-listener -visitor -o ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR} -package antlr4 ${GFOURS}
        DEPENDS ${GFOURS}
    )
endif()

message(STATUS "ANTLR generated: ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}")
include_directories(${ANTLR_${PROJECT_NAME}_OUTPUT_DIR})

# =========================================================
# 4. CONFIGURACIÓN DE LLVM
# =========================================================
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# [HÍBRIDO] Selección de librerías según el sistema operativo
if(WIN32)
    # [WIN32] En MSYS2 es más seguro mapear componentes explícitamente
    llvm_map_components_to_libnames(llvm_libs core support executionengine mcjit interpreter native)
    message(STATUS "Using LLVM component libraries (Windows/MSYS2 mode)")
else()
    # [LINUX] Lógica original de tu compañero (Busca librería monolítica primero)
    find_library(LLVM_MAIN_LIB NAMES LLVM PATHS ${LLVM_LIBRARY_DIRS} NO_DEFAULT_PATH)
    if(LLVM_MAIN_LIB)
        set(llvm_libs ${LLVM_MAIN_LIB})
        message(STATUS "Using main LLVM library: ${LLVM_MAIN_LIB}")
    else()
        llvm_map_components_to_libnames(llvm_libs all)
        message(STATUS "Using LLVM component libraries (Fallback)")
    endif()
endif()

# =========================================================
# 5. COMPILACIÓN DEL EJECUTABLE
# =========================================================
file(GLOB SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${ANTLR_${PROJECT_NAME}_CXX_OUTPUTS})

# [WIN32] Necesitamos buscar la librería runtime de ANTLR explícitamente en MSYS2
if(WIN32)
    find_library(ANTLR4_LIB NAMES antlr4-runtime PATHS "C:/msys64/ucrt64/lib" NO_DEFAULT_PATH)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ANTLR4_LIB} ${llvm_libs})
else()
    # [LINUX] Enlace estándar
    target_link_libraries(${PROJECT_NAME} PRIVATE antlr4-runtime ${llvm_libs})
endif()

target_include_directories(
  ${PROJECT_NAME} PRIVATE
  ${ANTLR_INCLUDE_DIR}
  ${ANTLR_${PROJECT_NAME}_OUTPUT_DIR}
  ${LLVM_INCLUDE_DIRS}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# [WIN32] Copiar DLLs necesarias al lado del ejecutable para que corra
if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/msys64/ucrt64/bin/libantlr4-runtime.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()

# vim: set ts=4 sw=4 et sts=0 :