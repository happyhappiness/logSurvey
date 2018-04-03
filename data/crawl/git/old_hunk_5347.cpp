	test_cmp expect output
'

test_expect_success 'appending empty string does not change existing note' '
	git notes append -m "" &&
	git notes show > output &&