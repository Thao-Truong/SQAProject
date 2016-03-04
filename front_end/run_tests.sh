#!/bin/bash
for i in ./Tests/login/*; do
	echo "running test $i"
	./banksys $i/current_accounts $i/actual_transactions < $i/input > $i/actual_output
done;
echo "done"