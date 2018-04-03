
test_expect_success 'OPT_DATE() works' '
	test-parse-options -t "1970-01-01 00:00:01 +0000" \
		foo -q > output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat > expect <<EOF
Callback: "four", 0
boolean: 5
integer: 4
