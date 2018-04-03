
	check_fsck &&

	git reflog refs/heads/master >output &&
	test_line_count = 4 output
'

test_expect_success rewind '
