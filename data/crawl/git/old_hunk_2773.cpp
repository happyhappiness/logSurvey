	test_must_fail git fast-import <input
'

test_expect_success 'git branch shows badly named ref' '
	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git branch >output &&
	grep -e "broken\.\.\.ref" output
'

test_expect_success 'branch -d can delete badly named ref' '
	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git branch -d broken...ref &&
	git branch >output &&
	! grep -e "broken\.\.\.ref" output
'

test_expect_success 'branch -D can delete badly named ref' '
	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git branch -D broken...ref &&
	git branch >output &&
	! grep -e "broken\.\.\.ref" output
'

