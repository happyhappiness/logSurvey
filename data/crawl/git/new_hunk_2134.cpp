EOF

test_expect_success 'test help' '
	test_must_fail test-parse-options -h >output 2>output.err &&
	test_must_be_empty output.err &&
	test_i18ncmp expect output
'

mv expect expect.err

cat >expect.template <<\EOF
boolean: 0
integer: 0
magnitude: 0
