		git difftool --dir-diff $symlinks --extcmd ls branch >output &&
		# "sub" must only exist in "right"
		# "file" and "file2" must be listed in both "left" and "right"
		test "1" = $(grep sub output | wc -l) &&
		test "2" = $(grep file"$" output | wc -l) &&
		test "2" = $(grep file2 output | wc -l)
	)
'

