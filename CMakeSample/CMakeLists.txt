cmake_minimum_required(VERSION 3.10)

# set the project name

project(Tutorial VERSION 1.0)

# add the executable
add_executable(Tutorial tutorial.cxx)

# configure a header file to pass the version number to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

target_include_directories( Turtorial PUBLIC 
														"${PROJECT_BINARY_DIR}" 
													)
