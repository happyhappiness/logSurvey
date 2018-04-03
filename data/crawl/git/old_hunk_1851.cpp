	key = value
	EOF
	test_must_fail git config --get section.key >actual 2>error &&
	grep " line 2 " error
'

test_expect_success 'barf on incomplete string' '
