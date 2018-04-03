#	untracked
EOF
test_expect_success 'status -unormal' '
	git status -unormal >output &&
	test_cmp expect output
'
