test_expect_success 'difftool.<tool>.path' '
	test_config difftool.tkdiff.path echo &&
	git difftool --tool=tkdiff --no-prompt branch >output &&
	grep file output >grep-output &&
	test_line_count = 1 grep-output
'

test_expect_success 'difftool --extcmd=cat' '
