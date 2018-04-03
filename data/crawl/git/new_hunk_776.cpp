		git difftool --dir-diff $symlinks --extcmd ls branch >output &&
		# "sub" must only exist in "right"
		# "file" and "file2" must be listed in both "left" and "right"
		grep sub output > sub-output &&
		test_line_count = 1 sub-output &&
		grep file"$" output >file-output &&
		test_line_count = 2 file-output &&
		grep file2 output >file2-output &&
		test_line_count = 2 file2-output
	)
'

