cmake_minimum_required(VERSION 3.27)
project(AI_AUTOMATION)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Define the source files for the C++ executable
set(SOURCE_FILES main.cpp)

# Add the C++ executable target
add_executable(AI_AUTOMATION ${SOURCE_FILES})

# Find the Python interpreter
find_package(Python3 REQUIRED)

# Add a custom command to run the Python script after building the C++ executable
add_custom_command(TARGET AI_AUTOMATION POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Running Python script..."
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/test.py
)
