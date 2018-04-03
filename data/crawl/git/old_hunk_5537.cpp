
test_expect_success 'git ls-files --unmerged' '
	git ls-files --unmerged > ls-files-unmerged.output &&
	cmp ls-files-unmerged.expect ls-files-unmerged.output
'

test_expect_success 'git-merge-index' '
