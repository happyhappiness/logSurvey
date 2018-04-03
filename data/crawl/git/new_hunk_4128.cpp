
'

test_expect_success 'status -s -z -b' '
	tr "\\n" Q <expect >expect.q &&
	mv expect.q expect &&
	git status -s -z -b >output &&
	nul_to_q <output >output.q &&
	mv output.q output &&
	test_cmp expect output
'

test_expect_success 'setup dir3' '
	mkdir dir3 &&
	: >dir3/untracked1 &&
