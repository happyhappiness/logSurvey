	git bisect next
'

test_expect_success 'bisect reset removes packed refs' '
	git bisect reset &&
	git bisect start &&
