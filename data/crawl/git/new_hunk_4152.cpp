test_expect_success 'massive simple rename does not spam added files' '
	sane_unset GIT_MERGE_VERBOSITY &&
	git merge --no-stat simple-rename | grep -v Removing >output &&
	test_line_count -lt 5 output
'

test_done
