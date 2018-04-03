test_expect_success 'git branch cannot create a badly named ref' '
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	test_must_fail git branch broken...ref &&
	git branch >output &&
	! grep -e "broken\.\.\.ref" output
'

