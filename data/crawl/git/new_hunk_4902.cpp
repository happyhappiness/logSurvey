	grep "fatal: Log for [^ ]* only has [0-9][0-9]* entries." error
'

test_expect_success 'relative path not found' '
	(
		cd subdir &&
		test_must_fail git rev-parse HEAD:./nonexistent.txt 2>error &&
		grep subdir/nonexistent.txt error
	)
'

test_expect_success 'relative path outside worktree' '
	test_must_fail git rev-parse HEAD:../file.txt >output 2>error &&
	test -z "$(cat output)" &&
	grep "outside repository" error
'

test_expect_success 'relative path when cwd is outside worktree' '
	test_must_fail git --git-dir=.git --work-tree=subdir rev-parse HEAD:./file.txt >output 2>error &&
	test -z "$(cat output)" &&
	grep "relative path syntax can.t be used outside working tree." error
'

test_expect_success 'relative path when startup_info is NULL' '
	test_must_fail test-match-trees HEAD:./file.txt HEAD:./file.txt 2>error &&
	grep "BUG: startup_info struct is not initialized." error
'

test_done