A  dir2/added
EOF
test_expect_success 'status -s -uno' '
	git status -s -uno >output &&
	test_cmp expect output
'