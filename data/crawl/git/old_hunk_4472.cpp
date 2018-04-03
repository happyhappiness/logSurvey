#	output
#	untracked
EOF
test_expect_success 'status -unormal' '
	git status -unormal >output &&
	test_cmp expect output
'

test_expect_success 'status (status.showUntrackedFiles normal)' '
	git config status.showuntrackedfiles normal
	git status >output &&
	test_cmp expect output
'
