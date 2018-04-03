EOF
test_expect_success 'status -uall' '
	git status -uall >output &&
	rm -rf dir3 &&
	test_cmp expect output
'

