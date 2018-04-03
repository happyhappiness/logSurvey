
'

test_expect_success 'without -space' '

	git config core.whitespace -space
	git diff --color >output
	grep "$blue_grep" output >error
