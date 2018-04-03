test_expect_success 'status with added file in submodule' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	git status >output &&
	grep "modified:   sub" output
'

test_expect_success 'status with added file in submodule (porcelain)' '
