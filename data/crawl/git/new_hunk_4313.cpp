	EOF
'

test_expect_success 'status with untracked file in submodule' '
	(cd sub && git reset --hard) &&
	echo "content" >sub/new-file &&
	git status >output &&
	test_i18ngrep "modified:   sub (untracked content)" output
'

test_expect_success 'status -uno with untracked file in submodule' '
	git status -uno >output &&
	test_i18ngrep "^nothing to commit" output
'

test_expect_success 'status with untracked file in submodule (porcelain)' '
