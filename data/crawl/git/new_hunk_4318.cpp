	EOF
'

test_expect_success 'status with added and untracked file in modified submodule' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	echo "content" >sub/new-file &&
	git status >output &&
	test_i18ngrep "modified:   sub (new commits, modified content, untracked content)" output
'

test_expect_success 'status with added and untracked file in modified submodule (porcelain)' '
