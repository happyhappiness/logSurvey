	 git commit -m "added .real to .gitignore" .gitignore
'

test_expect_success 'status with added file in modified submodule with .git file' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	git status >output &&
	test_i18ngrep "modified:   sub (new commits, modified content)" output
'

test_expect_success 'rm submodule contents' '
	rm -rf sub/* sub/.git
'

test_expect_success 'status clean (empty submodule dir)' '
	git status >output &&
	test_i18ngrep "nothing to commit" output
'

test_expect_success 'status -a clean (empty submodule dir)' '
	test_must_fail git commit --dry-run -a >output &&
	test_i18ngrep "nothing to commit" output
'

test_done