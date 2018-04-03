test_expect_success 'rewind2' '

	test_tick && git reset --hard HEAD~2 &&
	test_line_count = 4 .git/logs/refs/heads/master
'

test_expect_success '--expire=never' '
