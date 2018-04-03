	grep "nothing to commit" output
'

test_expect_success C_LOCALE_OUTPUT 'status with modified file in submodule' '
	(cd sub && git reset --hard) &&
	echo "changed" >sub/foo &&
	git status >output &&
