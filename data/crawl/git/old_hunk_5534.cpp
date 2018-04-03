test_expect_success 'git show-branch (part 3)' '
	git show-branch --topo-order --more=2 master mybranch \
		> show-branch3.output &&
	cmp show-branch3.expect show-branch3.output
'

test_expect_success 'rewind to "Some fun." and "Some work."' '
