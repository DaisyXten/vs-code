1. add_subdirectory must be added into each layer's CMakeList.txt layer by layer
2. Difference with include
The most commonly used rule is "One CMakeLists.txt per target". So your option No. 1.

* To achieve this your project structure may have to adapt, if "each source file from the subfolders creates a separate executable". And the root CMakeLists.txt is your starting point and contains the project() command. It's important to note that

* CMake will mirror your add_subdirectory() and CMakeLists.txt directory structure in its generated build environment
* CMake will create a new variable scope with each add_subdirectory() call (the big difference to using include() command)
