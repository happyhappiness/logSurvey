	cat >expected &&
	# We're not interested in the error
	# "fatal: The remote end hung up unexpectedly":
	test_i18ngrep -E '^(fatal|warning):' <error | grep -v 'hung up' >actual | sort &&
	test_i18ncmp expected actual
}

test_expect_success 'setup' '
