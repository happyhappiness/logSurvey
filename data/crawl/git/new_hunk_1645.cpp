	)
'

run_dir_diff_test 'difftool --dir-diff from subdirectory with GIT_DIR set' '
	(
		GIT_DIR=$(pwd)/.git &&
		export GIT_DIR &&
		GIT_WORK_TREE=$(pwd) &&
		export GIT_WORK_TREE &&
		cd sub &&
		git difftool --dir-diff $symlinks --extcmd ls \
			branch -- sub >output &&
		grep sub output &&
		! grep file output
	)
'

run_dir_diff_test 'difftool --dir-diff when worktree file is missing' '
	test_when_finished git reset --hard &&
	rm file2 &&