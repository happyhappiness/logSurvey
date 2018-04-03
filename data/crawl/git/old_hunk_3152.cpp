	! test -d bar
'

test_expect_success 'force removal of nested git work tree' '
	rm -fr foo bar baz &&
	mkdir -p foo bar baz/boo &&