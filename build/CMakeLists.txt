cmake_minimum_required(VERSION 3.12)
project(Lychan23special)

# Set the C++ standard (optional)
set(CMAKE_CXX_STANDARD 11)

# Set the vcpkg root directory
set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg" CACHE STRING "")

# Include the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Add your source files
set(SOURCES
    src/main.cpp
    src/other_file.cpp
)

# Add your header files (optional)
set(HEADERS
    include/your_header.hpp
)

# Add an executable target
add_executable(YourExecutable ${SOURCES} ${HEADERS})

# Add any necessary dependencies (e.g., libraries from vcpkg)
target_link_libraries(YourExecutable
    # list your dependencies here
    # for example: PRIVATE fmt::fmt
)

# Specify any additional include directories (optional)
target_include_directories(YourExecutable PRIVATE
    include
)
