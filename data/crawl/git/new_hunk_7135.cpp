	test-parse-options --boolean --integer 1729 --boolean --string2=321 \
		> output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
'

cat > expect << EOF
