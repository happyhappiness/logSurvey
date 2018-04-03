
test_expect_success 'git diff-files -p' '
	git diff-files -p > diff.output &&
	test_cmp diff.expect diff.output
'

test_expect_success 'git diff' '
	git diff > diff.output &&
	test_cmp diff.expect diff.output
'

test_expect_success 'tree' '
