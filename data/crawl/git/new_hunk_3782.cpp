test_expect_success PERL 'say no to the first file' '
	(echo n && echo) >input &&
	git difftool -x cat branch <input >output &&
	grep m2 output &&
	grep br2 output &&
	! grep master output &&
	! grep branch output
'

test_expect_success PERL 'say no to the second file' '
	(echo && echo n) >input &&
	git difftool -x cat branch <input >output &&
	grep master output &&
	grep branch output &&
	! grep m2 output &&
	! grep br2 output
'

test_expect_success PERL 'difftool --tool-help' '
	git difftool --tool-help >output &&
	grep tool output
'

test_expect_success PERL 'setup change in subdirectory' '
