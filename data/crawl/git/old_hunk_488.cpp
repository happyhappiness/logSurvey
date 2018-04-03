	git status -s -z -b >output &&
	nul_to_q <output >output.q &&
	mv output.q output &&
	test_cmp expect output
'

test_expect_success 'setup dir3' '
