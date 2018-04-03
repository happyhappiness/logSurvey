test_expect_success 'git-status honours core.excludesfile' \
	'diff -u expect output'

test_done
