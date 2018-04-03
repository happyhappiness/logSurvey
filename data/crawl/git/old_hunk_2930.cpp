	expecting_failure=$2

	if test "${GIT_TEST_CHAIN_LINT:-1}" != 0; then
		# 117 is magic because it is unlikely to match the exit
		# code of other programs
		test_eval_ "(exit 117) && $1"
		if test "$?" != 117; then
			error "bug in the test script: broken &&-chain: $1"
		fi
	fi

	setup_malloc_check