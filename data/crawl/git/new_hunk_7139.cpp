test_expect_success 'keep some options as arguments' '
	test-parse-options --quux > output 2> output.err &&
        test ! -s output.err &&
        test_cmp expect output
'

test_done
