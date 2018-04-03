	test_cmp expect output
'

test_expect_success '--local requires a repo' '
	# we expect 128 to ensure that we do not simply
	# fail to find anything and return code "1"
	test_expect_code 128 nongit git config --local foo.bar