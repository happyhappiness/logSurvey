'

test_expect_success 'git diff-index -p HEAD' '
	echo "Initial commit" | \
	git commit-tree $(git write-tree) 2>&1 > .git/refs/heads/master &&
	git diff-index -p HEAD > diff.output &&
	cmp diff.expect diff.output
'
