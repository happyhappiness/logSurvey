test_expect_success 'status (2)' '

	git status > output &&
	test_cmp expect output

'

