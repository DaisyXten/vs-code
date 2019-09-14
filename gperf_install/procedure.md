[How to set gperf path][https://stackoverflow.com/questions/40706802/how-to-set-gperftools-path-variables-gperftools-libraries-gperftools-include-dir]

[Answer 1]
Not sure which script FindGperftools.cmake you use, but this one searches for library tcmalloc_and_profiler and header gperftools/heap-profiler.h.

But package google-perftools doesn't provide these files. (Actually, this package doesn't provide any headers or library.)

The library is provided by libgoogle-perftools4 package. Probably, there are should be some devel package which provides the header.


[Answer 2]
# set the path to the library folder
link_directories(/usr/local/lib)

#Append Gperftools_DIR 
LIST(APPEND CMAKE_MODULE_PATH "/DirectoryWhereTheFindGperftools.cmakeIs")

find_package(Gperftools REQUIRED)


