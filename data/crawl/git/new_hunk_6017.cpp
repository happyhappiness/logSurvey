verbose: 2
quiet: no
dry run: no
file: prefix/fi.le
EOF

test_expect_success 'long options' '
	test-parse-options --boolean --integer 1729 --boolean --string2=321 \
		--verbose --verbose --no-dry-run --abbrev=10 --file fi.le\
		> output 2> output.err &&
	test ! -s output.err &&
	test_cmp expect output
