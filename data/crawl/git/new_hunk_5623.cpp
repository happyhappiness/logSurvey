'
check_all_output

test_expect_success 'ls-files -i lists only tracked-but-ignored files' '
	echo content >other-file &&
	git add other-file &&
	echo file >expect &&
	git ls-files -i --exclude-standard >output &&
	test_cmp expect output
'

test_done