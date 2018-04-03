	git diff expect output
'

cat > expect << EOF
boolean: 0
integer: 2
string: (not set)
EOF

test_expect_success 'unambiguously abbreviated option' '
	test-parse-options --int 2 --boolean --no-bo > output 2> output.err &&
	test ! -s output.err &&
	git diff expect output
'

test_expect_success 'unambiguously abbreviated option with "="' '
	test-parse-options --int=2 > output 2> output.err &&
	test ! -s output.err &&
	git diff expect output
'

test_expect_failure 'ambiguously abbreviated option' '
	test-parse-options --strin 123;
        test $? != 129
'

test_done