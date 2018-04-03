	(
		cd limit-by-paths &&
		git fast-export master~2..master~1 > output &&
		test_cmp expected output
	)
'
