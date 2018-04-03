
test_expect_success 'git branch' '
	git branch > branch.output &&
	test_cmp branch.expect branch.output
'

test_expect_success 'git resolve now fails' '
