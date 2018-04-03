	test_must_fail git rev-parse foobar:file.txt 2>error &&
	grep "Invalid object name '"'"'foobar'"'"'." error &&
	test_must_fail git rev-parse foobar 2> error &&
	grep "unknown revision or path not in the working tree." error
'

test_expect_success 'incorrect file in sha1:path' '
