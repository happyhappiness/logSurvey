	test_cmp expect output
'

cat >expect <<\EOF
boolean: 6
integer: 0
magnitude: 0
timestamp: 0
string: (not set)
abbrev: 7
verbose: -1
quiet: 0
dry run: no
file: (not set)
EOF

test_expect_success 'OPT_BIT() works' '
	test-parse-options -bb --or4 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

test_expect_success 'OPT_NEGBIT() works' '
	test-parse-options -bb --no-neg-or4 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

test_expect_success 'OPT_COUNTUP() with PARSE_OPT_NODASH works' '
	test-parse-options + + + + + + >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat >expect <<\EOF
boolean: 0
integer: 12345
magnitude: 0
timestamp: 0
string: (not set)
abbrev: 7
verbose: -1
quiet: 0
dry run: no
file: (not set)
EOF

test_expect_success 'OPT_NUMBER_CALLBACK() works' '
	test-parse-options -12345 >output 2>output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat >expect <<\EOF
