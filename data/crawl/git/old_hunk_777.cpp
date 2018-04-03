		git difftool --dir-diff $symlinks --extcmd ls v1 >output &&
		# "sub" and "file" exist in both v1 and HEAD.
		# "file2" is unchanged.
		test "2" = $(grep sub output | wc -l) &&
		test "2" = $(grep file output | wc -l) &&
		test "0" = $(grep file2 output | wc -l)
	)
'

