'

test_expect_success 'unambiguously abbreviated option with "="' '
	test-parse-options --int=2 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

test_expect_success 'ambiguously abbreviated option' '
	test_expect_code 129 test-parse-options --strin 123
'

cat >expect <<\EOF
boolean: 0
integer: 0
magnitude: 0
timestamp: 0
string: 123
abbrev: 7
verbose: -1
quiet: 0
dry run: no
file: (not set)
EOF

test_expect_success 'non ambiguous option (after two options it abbreviates)' '
	test-parse-options --st 123 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat >typo.err <<\EOF
