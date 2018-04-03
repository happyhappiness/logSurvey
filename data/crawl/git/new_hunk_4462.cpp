	EOF
'

test_expect_success C_LOCALE_OUTPUT 'status with added file in submodule' '
	(cd sub && git reset --hard && echo >foo && git add foo) &&
	git status >output &&
	grep "modified:   sub (modified content)" output
