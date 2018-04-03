EOF


test_expect_success 'status without relative paths' '

	git config status.relativePaths false
	(cd dir1 && git status) >output &&
	test_cmp expect output

