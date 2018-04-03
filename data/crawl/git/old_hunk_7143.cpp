test_expect_success 'status with relative paths' '

	(cd dir1 && git status) > output &&
	git diff expect output

'

