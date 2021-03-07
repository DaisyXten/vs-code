add_library(${MATH_TARGET} SHARED math.cpp)
target_include_directories(${MATH_TARGET} PRIVATE ${INCLUDE_DIRECTORIES})
