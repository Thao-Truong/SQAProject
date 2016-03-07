#!/bin/bash
# Test directories and their order
test_directories=("login" "logout" "accountsfile" "withdrawal" "transfer" "paybill" "deposit" "create" "delete" "disable" "enable" "changeplan")

for test_dir in "${test_directories[@]}"
	do
		echo "Test Directory: $test_dir"

		for i in ./Tests/$test_dir/*; do
			echo "checking outputs of test $i"

			

			if diff -q $i/actual_output $i/expected_output > /dev/null;
			then
				echo -e "test success"
			else
				echo -e "test fail"
				diff $i/actual_output $i/expected_output
			fi

		done;
	done;

echo "Comparison complete"
