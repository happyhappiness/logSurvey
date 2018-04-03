	cat >expected &&
	# We're not interested in the error
	# "fatal: The remote end hung up unexpectedly":
	grep -E '^(fatal|warning):' <error | grep -v 'hung up' >actual | sort &&
	test_cmp expected actual
}

test_expect_success 'setup' '
