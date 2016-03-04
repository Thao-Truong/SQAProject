chdir inputs
foreach i (*)
	echo “running test $i”
	banksys currentaccounts.txt ../outputs/$i.atf \ < $i > ../outputs/$i.out
end	