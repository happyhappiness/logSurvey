'

test_expect_success 'unambiguously abbreviated option with "="' '
	test-parse-options --expect="integer: 2" --int=2
'

test_expect_success 'ambiguously abbreviated option' '
	test_expect_code 129 test-parse-options --strin 123
'

test_expect_success 'non ambiguous option (after two options it abbreviates)' '
	test-parse-options --expect="string: 123" --st 123
'

cat >typo.err <<\EOF
