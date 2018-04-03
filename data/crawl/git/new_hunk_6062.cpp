	test_cmp expect output
'

test_expect_success 'OPT_NEGBIT() and OPT_SET_INT() work' '
	test-parse-options --set23 -bbbbb --neg-or4 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

cat > expect <<EOF
boolean: 6
integer: 0
timestamp: 0
string: (not set)
abbrev: 7
verbose: 0
quiet: no
dry run: no
EOF

test_expect_success 'OPT_BIT() works' '
	test-parse-options -bb --or4 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

test_expect_success 'OPT_NEGBIT() works' '
	test-parse-options -bb --no-neg-or4 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

test_done
