	commit=$(echo "Initial commit" | git commit-tree $tree) &&
	git update-ref HEAD $commit &&
	git diff-index -p HEAD > diff.output &&
	test_cmp diff.expect diff.output
'

test_expect_success 'git diff HEAD' '
	git diff HEAD > diff.output &&
	test_cmp diff.expect diff.output
'

cat > whatchanged.expect << EOF
