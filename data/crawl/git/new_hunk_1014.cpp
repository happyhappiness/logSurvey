	test_cmp expect output
'

test_expect_success 'multiple quiet levels' '
	test-parse-options --expect="quiet: 3" -q -q -q
'

test_expect_success 'multiple verbose levels' '
	test-parse-options --expect="verbose: 3" -v -v -v
'

test_expect_success '--no-quiet sets --quiet to 0' '
	test-parse-options --expect="quiet: 0" --no-quiet
'

test_expect_success '--no-quiet resets multiple -q to 0' '
	test-parse-options --expect="quiet: 0" -q -q -q --no-quiet
'

test_expect_success '--no-verbose sets verbose to 0' '
	test-parse-options --expect="verbose: 0" --no-verbose
'

test_expect_success '--no-verbose resets multiple verbose to 0' '
	test-parse-options --expect="verbose: 0" -v -v -v --no-verbose
'

test_done