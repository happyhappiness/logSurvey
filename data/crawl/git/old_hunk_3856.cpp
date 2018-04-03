'

test_expect_success PERL 'difftool -d' '
	diff=$(git difftool -d --extcmd ls branch) &&
	echo "$diff" | stdin_contains sub &&
	echo "$diff" | stdin_contains file
'

test_expect_success PERL 'difftool --dir-diff' '
	diff=$(git difftool --dir-diff --extcmd ls branch) &&
	echo "$diff" | stdin_contains sub &&
	echo "$diff" | stdin_contains file
'

test_expect_success PERL 'difftool --dir-diff ignores --prompt' '
	diff=$(git difftool --dir-diff --prompt --extcmd ls branch) &&
	echo "$diff" | stdin_contains sub &&
	echo "$diff" | stdin_contains file
'

test_expect_success PERL 'difftool --dir-diff from subdirectory' '
	(
		cd sub &&
		diff=$(git difftool --dir-diff --extcmd ls branch) &&
		echo "$diff" | stdin_contains sub &&
		echo "$diff" | stdin_contains file
	)
'
