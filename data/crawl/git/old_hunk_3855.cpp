'

test_expect_success PERL 'say no to the first file' '
	diff=$( (echo n; echo) | git difftool -x cat branch ) &&

	echo "$diff" | stdin_contains m2 &&
	echo "$diff" | stdin_contains br2 &&
	echo "$diff" | stdin_doesnot_contain master &&
	echo "$diff" | stdin_doesnot_contain branch
'

test_expect_success PERL 'say no to the second file' '
	diff=$( (echo; echo n) | git difftool -x cat branch ) &&

	echo "$diff" | stdin_contains master &&
	echo "$diff" | stdin_contains branch &&
	echo "$diff" | stdin_doesnot_contain m2 &&
	echo "$diff" | stdin_doesnot_contain br2
'

test_expect_success PERL 'difftool --tool-help' '
	tool_help=$(git difftool --tool-help) &&
	echo "$tool_help" | stdin_contains tool
'

test_expect_success PERL 'setup change in subdirectory' '
