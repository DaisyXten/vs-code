cmake_minimum_required(VERSION 3.14)
project(cmake_01_sample VERSION 0.1.0 LANGUAGE C CXX)

# This is a single line comment

# The different types of targets
# A target usually is 
# 1. executable
# 2. library
# 3. custom target

add_library(

# There are 3 keywords controlling the propagation
# 1. PRIVATE means there is no propagation and the property is only applied to the target

