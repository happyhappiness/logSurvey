	git log -2 > output &&
	test_cmp expect-multiline output
'

test_done