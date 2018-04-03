	test_must_fail git log :!does-not-exist
'

test_expect_success 'command line pathspec parsing for "git log"' '
	git reset --hard &&
	>a &&