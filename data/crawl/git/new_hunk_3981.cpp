#
# and 'side' should be the last branch

test_expect_success '@{-1} works' '
	test_cmp_rev side @{-1}
'

test_expect_success '@{-1}~2 works' '
	test_cmp_rev side~2 @{-1}~2
'

test_expect_success '@{-1}^2 works' '
	test_cmp_rev side^2 @{-1}^2
'

test_expect_success '@{-1}@{1} works' '
	test_cmp_rev side@{1} @{-1}@{1}
'

test_expect_success '@{-2} works' '
	test_cmp_rev master @{-2}
'

test_expect_success '@{-3} fails' '
