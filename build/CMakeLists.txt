cmake_minimum_required(VERSION 3.12)
project(Lychan23Special)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the path to the Vcpkg toolchain file
set(VCPKG_TOOLCHAIN "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Include the Vcpkg toolchain file
if(EXISTS ${VCPKG_TOOLCHAIN})
    message(STATUS "Using Vcpkg toolchain file: ${VCPKG_TOOLCHAIN}")
    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_TOOLCHAIN})
else()
    message(FATAL_ERROR "Vcpkg toolchain file not found: ${VCPKG_TOOLCHAIN}")
endif()

# Add your source files
set(SOURCES
    main.cpp
    # Add more source files here
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Find and link the required Vcpkg libraries
find_package(VcpkgLibrary1 REQUIRED)
find_package(VcpkgLibrary2 REQUIRED)
# Add more find_package() calls for other libraries

# Link the Vcpkg libraries to your executable
target_link_libraries(${PROJECT_NAME}
    Vcpkg::Library1
    Vcpkg::Library2
    # Link other libraries here
)
