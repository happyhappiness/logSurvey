	git branch goodref &&
	test_must_fail git branch -m goodref broken...ref &&
	test_cmp_rev master goodref &&
	git branch >output &&
	! grep -e "broken\.\.\.ref" output
'

