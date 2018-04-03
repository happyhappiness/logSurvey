EOF

test_expect_success 'alternative GIT_CONFIG' '
	GIT_CONFIG=other-config git config --list >output &&
	test_cmp expect output
'

test_expect_success 'alternative GIT_CONFIG (--file)' '
	git config --file other-config --list >output &&
	test_cmp expect output
'

test_expect_success 'alternative GIT_CONFIG (--file=-)' '
	git config --file - --list <other-config >output &&
	test_cmp expect output
'

test_expect_success 'setting a value in stdin is an error' '
	test_must_fail git config --file - some.value foo
'

test_expect_success 'editing stdin is an error' '
	test_must_fail git config --file - --edit
'

test_expect_success 'refer config from subdirectory' '
	mkdir x &&
	(
