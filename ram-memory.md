# Check the physical memory
[link](https://kerneltalks.com/linux/4-ways-to-check-size-of-physical-memory-in-linux/)

## commands
```
free -b
free -k
free -m
free -g

```

```
cat /proc/meminfo |grep MemTotal
```

virtual memory stats (vmstat)
```
vmstat -s
    132039544  total memory
      1218692  used memory
       181732  active memory
----output trimmed----
```

# Important tool to track the current memroy
dmesg | grep memory
