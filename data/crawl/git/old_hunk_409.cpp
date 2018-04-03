	test_cmp expect actual
'

test_expect_success POSIXPERM,SANITY 'proper error on non-accessible files' '
	chmod -r .git/config &&
	test_when_finished "chmod +r .git/config" &&