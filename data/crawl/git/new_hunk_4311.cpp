	git commit -m "Add submodule sub"
'

test_expect_success 'status clean' '
	git status >output &&
	test_i18ngrep "nothing to commit" output
'

test_expect_success 'commit --dry-run -a clean' '
	test_must_fail git commit --dry-run -a >output &&
	test_i18ngrep "nothing to commit" output
'

test_expect_success 'status with modified file in submodule' '
	(cd sub && git reset --hard) &&
	echo "changed" >sub/foo &&
	git status >output &&
	test_i18ngrep "modified:   sub (modified content)" output
'

test_expect_success 'status with modified file in submodule (porcelain)' '
