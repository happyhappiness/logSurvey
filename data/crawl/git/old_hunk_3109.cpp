EOF

test_expect_success 'long options' '
	test-parse-options --boolean --integer 1729 --boolean --string2=321 \
		--verbose --verbose --no-dry-run --abbrev=10 --file fi.le\
		--obsolete > output 2> output.err &&
	test_must_be_empty output.err &&
	test_cmp expect output
'
