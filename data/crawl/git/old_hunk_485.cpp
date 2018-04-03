	! grep -e "broken\.\.\.ref" output
'

test_expect_failure 'push --mirror can delete badly named ref' '
	top=$(pwd) &&
	git init src &&
	git init dest &&
