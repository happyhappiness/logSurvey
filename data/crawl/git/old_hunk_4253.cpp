	test_cmp expected actual
'

test_expect_success 'grep from a subdirectory to search wider area (1)' '
	mkdir -p s &&
	(