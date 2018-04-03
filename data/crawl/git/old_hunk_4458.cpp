	git commit -m "Add submodule sub"
'

test_expect_success 'status clean' '
	git status >output &&
	grep "nothing to commit" output
'

test_expect_success 'commit --dry-run -a clean' '
	test_must_fail git commit --dry-run -a >output &&
	grep "nothing to commit" output
'
