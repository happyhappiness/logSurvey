	grep "modified:   sub (untracked content)" output
'

test_expect_success 'status with untracked file in submodule (porcelain)' '
	git status --porcelain >output &&
	diff output - <<-\EOF
