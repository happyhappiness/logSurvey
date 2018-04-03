	)
'

run_dir_diff_test 'difftool --dir-diff when worktree file is missing' '
	test_when_finished git reset --hard &&
	rm file2 &&