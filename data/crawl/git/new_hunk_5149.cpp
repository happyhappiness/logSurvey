	git log -1 > output &&
	test_cmp expect output
'

test_expect_success 'git notes copy diagnoses too many or too few parameters' '
	test_must_fail git notes copy &&
	test_must_fail git notes copy one two three
'

test_done