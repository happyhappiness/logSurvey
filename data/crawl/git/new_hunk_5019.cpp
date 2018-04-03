	git add .
'

test_expect_success 'git -ls-files --with-tree should succeed from subdir' '
	# We have to run from a sub-directory to trigger prune_path
	# Then we finally get to run our --with-tree test
	(
		cd sub &&
		git ls-files --with-tree=HEAD~1 >../output
	)
'

test_expect_success \
