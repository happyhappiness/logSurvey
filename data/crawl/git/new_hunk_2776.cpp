	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git branch -m broken...ref renamed &&
	test_cmp_rev master renamed &&
	git branch >output 2>error &&
	! grep -e "broken\.\.\.ref" error &&
	! grep -e "broken\.\.\.ref" output
'

test_expect_success 'push cannot create a badly named ref' '
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	test_must_fail git push "file://$(pwd)" HEAD:refs/heads/broken...ref &&
	git branch >output 2>error &&
	! grep -e "broken\.\.\.ref" error &&
	! grep -e "broken\.\.\.ref" output
'

