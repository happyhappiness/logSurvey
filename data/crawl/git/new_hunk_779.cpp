		git difftool --dir-diff $symlinks --extcmd ls v1 -- .>output &&
		# "sub" exists in v1 and HEAD
		# "file" is filtered out by the pathspec
		grep sub output >sub-output &&
		test_line_count = 2 sub-output &&
		! grep file output
	)
'
