## Check memory:
1. valgrind /usr/local/bin/valgrind --track-origins=yes  python -u ../train.py -c benchmark.yaml
2. check peak RSS usr/bin/time -v python -u ../train.py -c benchmark.yaml
3. mul.zip check memory 
```
###过滤出需要的进程ID

PID=$(ps aux| grep $PROCESS | grep -v 'grep' | awk '{​​​​​print $2;}​​​​​​​​​​​​')
echo "$PID"

while [ "$PID" != "" ]
do
    cat /proc/$PID/status | grep RSS >> "$LOG"
    sleep 10
    PID=$(ps aux| grep $PROCESS | grep -v 'grep' | awk '{​​​​​​​​​​​​print $2;}​​​​​​​​​​​​')
done
```
4. use Vtune
