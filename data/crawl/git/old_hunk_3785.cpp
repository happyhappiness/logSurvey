	test_cmp actual expect
'

test_expect_success PERL 'difftool --dir-diff ignores --prompt' '
	git difftool --dir-diff --prompt --extcmd ls branch >output &&
	stdin_contains sub <output &&
	stdin_contains file <output
'

test_expect_success PERL 'difftool --dir-diff from subdirectory' '
	(
		cd sub &&
		git difftool --dir-diff --extcmd ls branch >output &&
		stdin_contains sub <output &&
		stdin_contains file <output
	)
'

test_done