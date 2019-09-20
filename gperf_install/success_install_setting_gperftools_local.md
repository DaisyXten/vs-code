1. clone repo locally following this link: https://github.com/linux-on-ibm-z/docs/wiki/Building-gperftools
2. go to cmake/FindGperftools.cmake, on the top add one line 
```bash
set(Gperftools_ROOT_DIR /home/danqing/gperf)
```

export PATH=$PATH:/home/danqing/gperf/bin
