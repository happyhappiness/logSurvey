		git difftool --dir-diff $symlinks --extcmd ls v1 >output &&
		# "sub" and "file" exist in both v1 and HEAD.
		# "file2" is unchanged.
		grep sub output >sub-output &&
		test_line_count = 2 sub-output &&
		grep file output >file-output &&
		test_line_count = 2 file-output &&
		! grep file2 output
	)
'

