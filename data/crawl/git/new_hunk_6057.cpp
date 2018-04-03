	test_cmp expect output
'

test_expect_success 'OPT_BOOLEAN() with PARSE_OPT_NODASH works' '
	test-parse-options + + + + + + > output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

cat > expect <<EOF
boolean: 0
integer: 12345
