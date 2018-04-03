	cd local &&
	test_must_fail git push --all 2> error &&
	cat error &&
	grep -q "Reading from remote helper failed" error
	)
'

