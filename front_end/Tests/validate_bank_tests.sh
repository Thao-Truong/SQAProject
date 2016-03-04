chdir inputs
foreach i (*)
	echo “checking outputs of test $i”
	diff ../outputs/$i.atf ../expected/$i.etf
end