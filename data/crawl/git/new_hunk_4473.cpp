?? untracked
EOF
test_expect_success 'status -s -unormal' '
	git status -s -unormal >output &&
	test_cmp expect output
'
