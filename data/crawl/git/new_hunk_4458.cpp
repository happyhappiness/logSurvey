	git commit -m "Add submodule sub"
'

test_expect_success C_LOCALE_OUTPUT 'status clean' '
	git status >output &&
	grep "nothing to commit" output
'

test_expect_success C_LOCALE_OUTPUT 'commit --dry-run -a clean' '
	test_must_fail git commit --dry-run -a >output &&
	grep "nothing to commit" output
'
