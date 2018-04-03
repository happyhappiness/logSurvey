	 git commit -m "added .real to .gitignore" .gitignore
'

test_expect_success C_LOCALE_OUTPUT 'status with added file in modified submodule with .git file' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	git status >output &&
	grep "modified:   sub (new commits, modified content)" output
'

test_expect_success 'rm submodule contents' '
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

test_done