	! grep br2 output
'

test_expect_success 'ending prompt input with EOF' '
	git difftool -x cat branch </dev/null >output &&
	! grep master output &&
	! grep branch output &&
	! grep m2 output &&
	! grep br2 output
'

test_expect_success 'difftool --tool-help' '
	git difftool --tool-help >output &&
	grep tool output
'

test_expect_success 'setup change in subdirectory' '
	git checkout master &&
	mkdir sub &&
	echo master >sub/sub &&
