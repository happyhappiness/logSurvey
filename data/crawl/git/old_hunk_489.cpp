test_expect_success 'status -s -b with color.status' '

	git status -s -b | test_decode_color >output &&
	test_cmp expect output

'

