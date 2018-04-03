test_expect_success 'relative path outside worktree' '
	test_must_fail git rev-parse HEAD:../file.txt >output 2>error &&
	test -z "$(cat output)" &&
	grep "outside repository" error
'

test_expect_success 'relative path when cwd is outside worktree' '