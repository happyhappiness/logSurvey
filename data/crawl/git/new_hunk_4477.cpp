
test_expect_success 'status -s with color.ui' '

	git config color.ui always &&
	git status -s | test_decode_color >output &&
	test_cmp expect output
