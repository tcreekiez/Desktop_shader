cmake_minimum_required (VERSION 3.8)

project (Desktop_shader)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/res/*.cpp)
set(SOURCES ${SOURCES} ${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c)
include_directories(${CMAKE_SOURCE_DIR}/dependencies/glad/include)

include_directories(${CMAKE_SOURCE_DIR}/dependencies/sdl2/include)
file(GLOB_RECURSE SDL2_LIB ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/x64/*.lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)

add_executable(Desktop_shader ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIB}) 

file(COPY ${CMAKE_SOURCE_DIR}/shaders/fs.frag DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE})
file(COPY ${CMAKE_SOURCE_DIR}/shaders/vs.vert DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE})
file(COPY ${CMAKE_SOURCE_DIR}/dependencies/sdl2/lib/x64/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE})