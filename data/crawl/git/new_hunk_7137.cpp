test_expect_success 'unambiguously abbreviated option' '
	test-parse-options --int 2 --boolean --no-bo > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

test_expect_success 'unambiguously abbreviated option with "="' '
	test-parse-options --int=2 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

test_expect_success 'ambiguously abbreviated option' '
