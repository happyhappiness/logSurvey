'

test_expect_success 'git diff-index -p HEAD' '
	tree=$(git write-tree)
	commit=$(echo "Initial commit" | git commit-tree $tree) &&
	git update-ref HEAD $commit &&
	git diff-index -p HEAD > diff.output &&
	cmp diff.expect diff.output
'
