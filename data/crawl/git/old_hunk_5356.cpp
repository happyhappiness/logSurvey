	test_cmp expect-not-other output
'

test_expect_success 'Allow notes on non-commits (trees, blobs, tags)' '
	echo "Note on a tree" > expect
	git notes add -m "Note on a tree" HEAD: &&
	git notes show HEAD: > actual &&
