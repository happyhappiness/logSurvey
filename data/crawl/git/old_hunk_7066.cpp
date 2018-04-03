	test_cmp expect output
'

cat > expect.err << EOF
error: did you mean \`--boolean\` (with two dashes ?)
EOF

test_expect_success 'detect possible typos' '
	! test-parse-options -boolean > output 2> output.err &&
	test ! -s output &&
	test_cmp expect.err output.err
'

cat > expect <<EOF
boolean: 0
integer: 0
string: (not set)
arg 00: --quux
EOF

