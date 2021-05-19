cmake_minimum_required(VERSION 3.17)
project(Week5-6)

set(CMAKE_C_STANDARD 11)

# Setting Find cmake files path
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/ViewingLab/cmakeFiles)

# Define the executable.
add_executable(${PROJECT_NAME} ${SOURCES})

# Adding Source Directory
add_subdirectory(${PROJECT_SOURCE_DIR}/ViewingLab/src)

# Adding Include folder
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/ViewingLab/include)


# Unsetting old cache var's
unset(${FREEGLUT_LIBRARY} CACHE)

# Finding required lib's using FindXXX.cmake files in /cmakeFiles
message("")
find_package(OpenGL REQUIRED)
find_package(freeglut REQUIRED)
message("")



# Linking lib files to compiler
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${FREEGLUT_LIBRARY})

# Copy resource files
#add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E create_symlink
#        ${PROJECT_SOURCE_DIR}/res ${CMAKE_CURRENT_BINARY_DIR}/res )