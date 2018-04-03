
test_expect_success 'intermingled arguments' '
	test-parse-options a1 --string 123 b1 --boolean -j 13 -- --boolean \
		> output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'

cat > expect << EOF
boolean: 0
integer: 2
magnitude: 0
