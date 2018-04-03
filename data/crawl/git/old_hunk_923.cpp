	grep file output
'

run_dir_diff_test 'difftool --dir-diff from subdirectory' '
	(
		cd sub &&
		git difftool --dir-diff $symlinks --extcmd ls branch >output &&
		grep sub output &&
		grep file output
	)
'
