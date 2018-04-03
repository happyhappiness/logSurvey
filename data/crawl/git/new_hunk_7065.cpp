boolean: 2
integer: 1729
string: 123
abbrev: 7
verbose: 2
quiet: no
dry run: yes
EOF

test_expect_success 'short options' '
	test-parse-options -s123 -b -i 1729 -b -vv -n > output 2> output.err &&
	test_cmp expect output &&
	test ! -s output.err
'

cat > expect << EOF
boolean: 2
integer: 1729
string: 321
abbrev: 10
verbose: 2
quiet: no
dry run: no
EOF

test_expect_success 'long options' '
	test-parse-options --boolean --integer 1729 --boolean --string2=321 \
		--verbose --verbose --no-dry-run --abbrev=10 \
		> output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
