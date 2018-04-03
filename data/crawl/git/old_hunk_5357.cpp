	(cd sub && git reset --hard) &&
	echo "changed" >sub/foo &&
	git status >output &&
	grep "modified:   sub" output
'

test_expect_success 'status with modified file in submodule (porcelain)' '
