
	# Prefix the output with the command line arguments, and
	# replace SP with a dot both in the expecte and actual output
	# so that test_cmp would show the differene together with the
	# breakage in a way easier to consume by the debugging user.
	{
		echo "git show -s $*"
