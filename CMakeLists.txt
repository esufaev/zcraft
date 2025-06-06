cmake_minimum_required(VERSION 3.16)
project(zcraft)

include(FetchContent)

set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "" FORCE)

FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG        v0.1.36
)
FetchContent_MakeAvailable(glad)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG master
)

FetchContent_MakeAvailable(glfw)

include_directories(${CMAKE_SOURCE_DIR}/external)

# Указываем исходники внутри папки zcraft/
add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad GL)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${glfw_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}  # чтобы zcraft/ стал доступен для #include "zcraft/..."
)

target_link_libraries(zcraft PRIVATE glm)
