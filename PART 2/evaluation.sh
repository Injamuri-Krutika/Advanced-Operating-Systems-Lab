#!/bin/sh


echo "The Older and younger process are"
ps -eo pid,etime,comm | head -n 2
ps -eo pid,etime,comm | tail -n 1


echo "The largest and the smallest process are"

top -o +%MEM -bn1 | sed -n -e 7,8p
top -o +%MEM -bn1| tail -n 1

'**************************************************************************
Output :
***************************************************************************
The Older and younger process are
  PID     ELAPSED COMMAND
    1    01:53:30 systemd
 4486       00:00 ps
The largest and the smallest process are
  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 2667 user      20   0 4900724 653116   2180 S 188.5 17.1  84:45.48 ZMQbg/1
 4429 root      20   0       0      0      0 I   0.0  0.0   0:00.01 kworker/2:2
'
