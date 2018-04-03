        test_cmp expect output
'

cat > expect <<EOF
boolean: 0
integer: 1
string: default
abbrev: 7
verbose: 0
quiet: yes
dry run: no
arg 00: foo
EOF

test_expect_success 'OPT_DATE() and OPT_SET_PTR() work' '
	test-parse-options -t "1970-01-01 00:00:01 +0000" --default-string \
		foo -q > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

cat > expect <<EOF
Callback: "four", 0
boolean: 5
integer: 4
string: (not set)
abbrev: 7
verbose: 0
quiet: no
dry run: no
EOF

test_expect_success 'OPT_CALLBACK() and OPT_BIT() work' '
	test-parse-options --length=four -b -4 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

cat > expect <<EOF
Callback: "not set", 1
EOF

test_expect_success 'OPT_CALLBACK() and callback errors work' '
	test_must_fail test-parse-options --no-length > output 2> output.err &&
	test_cmp expect output &&
	test_cmp expect.err output.err
'

cat > expect <<EOF
boolean: 1
integer: 23
string: (not set)
abbrev: 7
verbose: 0
quiet: no
dry run: no
EOF

test_expect_success 'OPT_BIT() and OPT_SET_INT() work' '
	test-parse-options --set23 -bbbbb --no-or4 > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

# --or4
# --no-or4

test_done
