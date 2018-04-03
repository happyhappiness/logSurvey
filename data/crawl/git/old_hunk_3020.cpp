
	check_have A B C D E F G H I J K L &&

	test_line_count = 5 .git/logs/refs/heads/master
'

test_expect_success 'corrupt and check' '
