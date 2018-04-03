EOF

test_expect_success 'non ambiguous option (after two options it abbreviates)' '
	test-parse-options --st 123 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat >typo.err <<\EOF
error: did you mean `--boolean` (with two dashes ?)
EOF

test_expect_success 'detect possible typos' '
	test_must_fail test-parse-options -boolean >output 2>output.err &&
	test_must_be_empty output &&
	test_cmp typo.err output.err
'

cat >typo.err <<\EOF
error: did you mean `--ambiguous` (with two dashes ?)
EOF

test_expect_success 'detect possible typos' '
	test_must_fail test-parse-options -ambiguous >output 2>output.err &&
	test_must_be_empty output &&
	test_cmp typo.err output.err
'

cat >expect <<\EOF
boolean: 0
integer: 0
magnitude: 0
