		test_cmp "$expect" actual
	'

	test_expect_success "$cmd $verb statGraphWidth config" '
		git -c diff.statGraphWidth=26 $cmd $args >output
		grep " | " output >actual &&
		test_cmp "$expect" actual
	'

	test "$cmd" != diff || continue

	test_expect_success "$cmd --graph $verb not enough COLUMNS (big change)" '
		COLUMNS=40 git $cmd $args --graph >output
		grep " | " output >actual &&
		test_cmp "$expect-graph" actual
	'

	test_expect_success "$cmd --graph $verb statGraphWidth config" '
		git -c diff.statGraphWidth=26 $cmd $args --graph >output
