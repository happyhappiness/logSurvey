
test_expect_success 'test help' '
	test_must_fail test-parse-options -h > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

mv expect expect.err

cat > expect << EOF
boolean: 2
integer: 1729
