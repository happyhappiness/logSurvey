	test_i18ncmp expect.err actual.err
'

test_expect_success 'git add empty string should invoke warning' '
	git add "" 2>output &&
	test_i18ngrep "warning: empty strings" output
'

test_done