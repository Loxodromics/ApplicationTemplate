cmake_minimum_required(VERSION 3.20)

project(ApplicationTemplate VERSION 0.1.0 LANGUAGES CXX)

# C++20 standard requirement
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Conan integration
find_package(SDL3 REQUIRED CONFIG)
find_package(glm REQUIRED CONFIG)
find_package(spdlog REQUIRED CONFIG)

# Source files
add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	SDL3::SDL3
	glm::glm
	spdlog::spdlog
)