        test $? != 129
'

cat > expect << EOF
boolean: 0
integer: 0
string: 123
EOF

test_expect_success 'non ambiguous option (after two options it abbreviates)' '
	test-parse-options --st 123 > output 2> output.err &&
	test ! -s output.err &&
	git diff expect output
'

test_done
