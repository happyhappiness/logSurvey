		git difftool --dir-diff $symlinks --extcmd ls branch -- .>output &&
		# "sub" only exists in "right"
		# "file" and "file2" must not be listed
		grep sub output >sub-output &&
		test_line_count = 1 sub-output &&
		! grep file output
	)
'

