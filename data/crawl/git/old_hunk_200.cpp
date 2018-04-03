	git reset HEAD -- file1 file2 file3 &&
	test_must_fail git diff --quiet &&
	git diff > output &&
	test_cmp output expect &&
	git diff --cached > output &&
	test_cmp output cached_expect
'

test_expect_success 'test resetting the index at give paths' '
