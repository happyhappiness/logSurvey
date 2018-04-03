boolean: 2
integer: 1729
string: 123
EOF

test_expect_success 'short options' '
	test-parse-options -s123 -b -i 1729 -b > output 2> output.err &&
	test_cmp expect output &&
	test ! -s output.err
'
cat > expect << EOF
boolean: 2
integer: 1729
string: 321
EOF

test_expect_success 'long options' '
	test-parse-options --boolean --integer 1729 --boolean --string2=321 \
		> output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
