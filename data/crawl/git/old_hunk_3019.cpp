
	check_fsck &&

	test_line_count = 4 .git/logs/refs/heads/master
'

test_expect_success rewind '
