
git config advice.statusHints false

test_expect_success 'status (advice.statusHints false)' '

	git status >output &&
	test_cmp expect output
