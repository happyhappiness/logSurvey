EOF

test_expect_success 'OPT_CALLBACK() and OPT_BIT() work' '
	test-parse-options --length=four -b -4 > output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat > expect <<EOF
Callback: "not set", 1
EOF

test_expect_success 'OPT_CALLBACK() and callback errors work' '
	test_must_fail test-parse-options --no-length > output 2> output.err &&
	test_i18ncmp expect output &&
	test_i18ncmp expect.err output.err
'

cat > expect <<EOF
boolean: 1
integer: 23
magnitude: 0
