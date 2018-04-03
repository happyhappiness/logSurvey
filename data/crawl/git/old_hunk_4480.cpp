#	untracked
EOF
test_expect_success 'dry-run of partial commit excluding new file in index' '
	git commit --dry-run dir1/modified >output &&
	test_cmp expect output
'

