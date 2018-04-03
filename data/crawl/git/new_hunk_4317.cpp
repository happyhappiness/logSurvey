	EOF
'

test_expect_success 'status with untracked file in modified submodule' '
	(cd sub && git reset --hard) &&
	echo "content" >sub/new-file &&
	git status >output &&
	test_i18ngrep "modified:   sub (new commits, untracked content)" output
'

test_expect_success 'status with untracked file in modified submodule (porcelain)' '
