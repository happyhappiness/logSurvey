'

test_expect_success PERL 'say no to the first file' '
	(echo n && echo) >input &&
	git difftool -x cat branch <input >output &&
	stdin_contains m2 <output &&
	stdin_contains br2 <output &&
	stdin_doesnot_contain master <output &&
	stdin_doesnot_contain branch <output
'

test_expect_success PERL 'say no to the second file' '
	(echo && echo n) >input &&
	git difftool -x cat branch <input >output &&
	stdin_contains master <output &&
	stdin_contains branch  <output &&
	stdin_doesnot_contain m2 <output &&
	stdin_doesnot_contain br2 <output
'

test_expect_success PERL 'difftool --tool-help' '
	git difftool --tool-help >output &&
	stdin_contains tool <output
'

test_expect_success PERL 'setup change in subdirectory' '
