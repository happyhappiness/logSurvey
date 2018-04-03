	rm -rf sub/* sub/.git
'

test_expect_success C_LOCALE_OUTPUT 'status clean (empty submodule dir)' '
	git status >output &&
	grep "nothing to commit" output
'

test_expect_success C_LOCALE_OUTPUT 'status -a clean (empty submodule dir)' '
	test_must_fail git commit --dry-run -a >output &&
	grep "nothing to commit" output
'
