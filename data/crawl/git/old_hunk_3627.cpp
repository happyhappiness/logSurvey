	grep "^a.1" output
'

test_expect_success 'subdirectory ignore (setup)' '
	mkdir -p top/l1/l2 &&
	(