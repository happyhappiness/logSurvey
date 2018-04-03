
test_expect_success 'status -s without relative paths' '

	(cd dir1 && git status -s) >output &&
	test_cmp expect output

