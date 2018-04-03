	test "$(git rev-parse origin/b1)" = "origin/b1"
'

test_expect_success 'already deleted tracking branches ignored' '
	git branch -d -r origin/b3 &&
	git push origin :b3 >output 2>&1 &&
	! grep error output
'

test_done