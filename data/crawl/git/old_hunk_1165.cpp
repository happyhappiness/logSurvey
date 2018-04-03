	git format-patch --ignore-if-in-upstream HEAD
'

test_expect_success 'format-patch --signature' '
	git format-patch --stdout --signature="my sig" -1 >output &&
	grep "my sig" output
'

test_expect_success 'format-patch with format.signature config' '
