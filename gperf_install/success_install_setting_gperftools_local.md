1. clone repo locally following this link: https://github.com/linux-on-ibm-z/docs/wiki/Building-gperftools
2. go to cmake/FindGperftools.cmake, on the top add one line 
```bash
set(Gperftools_ROOT_DIR /home/danqing/gperf)
```
In `.bashrc`:
export PATH=$PATH:/home/danqing/gperf/bin
export Gperftools_ROOT_DIR=/home/danqing/gperf
export LD_LIBRARY_PATH=/home/danqing/Paddle/build/third_party/install/warpctc/lib:/home/danqing/gperf/lib
export GPERFTOOLS_INCLUDE_DIR=/home/danqing/gperf/include
