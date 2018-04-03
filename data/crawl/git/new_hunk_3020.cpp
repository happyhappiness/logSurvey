
	check_have A B C D E F G H I J K L &&

	git reflog refs/heads/master >output &&
	test_line_count = 5 output
'

test_expect_success 'corrupt and check' '
