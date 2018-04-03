test_expect_success '--mixed refreshes the index' '
	echo 123 >> file2 &&
	git reset --mixed HEAD > output &&
	test_cmp expect output
'

test_done
