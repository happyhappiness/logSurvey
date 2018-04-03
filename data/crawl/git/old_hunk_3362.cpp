EOF

test_expect_success 'alternative GIT_CONFIG' '
	GIT_CONFIG=other-config git config -l >output &&
	test_cmp expect output
'

test_expect_success 'alternative GIT_CONFIG (--file)' '
	git config --file other-config -l > output &&
	test_cmp expect output
'

test_expect_success 'refer config from subdirectory' '
	mkdir x &&
	(
