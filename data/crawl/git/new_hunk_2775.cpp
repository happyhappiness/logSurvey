	git branch goodref &&
	test_must_fail git branch -m goodref broken...ref &&
	test_cmp_rev master goodref &&
	git branch >output 2>error &&
	! grep -e "broken\.\.\.ref" error &&
	! grep -e "broken\.\.\.ref" output
'

