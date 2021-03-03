add_executable (${NEURON_TARGET} main.cpp)
target_include_directories(${NEURON_TARGET} PRIVATE ${INCLUDE_DIRECTORIES})
target_link_libraries(${NEURON_TARGET} PRIVATE ${MATH_TARGET})