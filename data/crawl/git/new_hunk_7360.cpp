	git diff expect.err output.err
'

cat > expect <<EOF
boolean: 0
integer: 0
string: (not set)
arg 00: --quux
EOF

test_expect_success 'keep some options as arguments' '
	test-parse-options --quux > output 2> output.err &&
        test ! -s output.err &&
        git diff expect output
'

test_done
