	test_cmp expect output
'

>expect

test_expect_success 'OPT_CALLBACK() and callback errors work' '
	test_must_fail test-parse-options --no-length >output 2>output.err &&
