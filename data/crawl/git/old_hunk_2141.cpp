EOF

test_expect_success 'OPT_BIT() and OPT_SET_INT() work' '
	test-parse-options --set23 -bbbbb --no-or4 > output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

test_expect_success 'OPT_NEGBIT() and OPT_SET_INT() work' '
	test-parse-options --set23 -bbbbb --neg-or4 > output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat > expect <<EOF
boolean: 6
integer: 0
magnitude: 0
