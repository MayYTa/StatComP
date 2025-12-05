# StatComP
User Friendly Statistical Language

---

# StatComp — Build & Run Instructions

This guide explains how to compile and run StatComp on Windows and Linux using CMake and Ninja.

## 🛠️ Requirements
- CMake ≥ 3.20
- Ninja build system
- C++ compiler:
  - Windows: MSVC (via Visual Studio Build Tools) or Clang via MSYS2/WSL
  - Linux: GCC or Clang
- ANTLR4 runtime (C++ version)
- LLVM libraries (if using LLVM backend)


## Before Setup

**Clone the github repo and access to the file CMakeLists.txt and add the addresses for all the files required**.


📦 Windows Setup
----------------
1. Install dependencies:
   - CMake: https://cmake.org/download/
   - Ninja: https://ninja-build.org/
   - Visual Studio Build Tools (select "C++ CMake tools for Windows")

2. Open a terminal (PowerShell or Developer Command Prompt)

3. Run the following commands:

   ```bash
   cmake -S . -B build -G "Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=1
   cmake --build build -j4
   .\build\StatComp.exe test.scp

📦 Linux Setup
------------------
1. Install dependencies 
  - sudo apt update
  - sudo apt install cmake ninja-build build-essential clang libantlr4-runtime-dev llvm-dev
2. In the same directory execute this commands 
  - cmake -S . -B build -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=1
  - cmake --build build -j4
  - ./build/StatComp test.scp



