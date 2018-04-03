	git reset HEAD -- file1 file2 file3 &&
	test_must_fail git diff --quiet &&
	git diff > output &&
	test_cmp expect output &&
	git diff --cached > output &&
	test_cmp cached_expect output
'

test_expect_success 'test resetting the index at give paths' '
