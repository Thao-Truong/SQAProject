#!/bin/bash
# Run tests in a defined order and produce actual output files

# Test directories and their order
test_directories=("login" "logout" "accountsfile" "withdrawal" "transfer" "paybill" "deposit" "create" "delete" "disable" "enable" "changeplan")

for test_dir in "${test_directories[@]}"
	do
		echo "Test Directory: $test_dir"

		for i in ./Tests/$test_dir/*; do
			echo "running test: $i"
			./banksys $i/current_accounts $i/actual_transactions < $i/input > $i/actual_output
		done;
	done;

echo "Tests complete"