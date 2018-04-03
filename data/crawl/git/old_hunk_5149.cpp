	git log -1 > output &&
	test_cmp expect output
'
test_done