#!/bin/bash
for i in $(ls); do
   diff $1 $i > /dev/null
   if [ $? = 0 ]; then
      echo $1 and $i are the same.
   else
      diff $1 $i >> logfile
   fi
done;
