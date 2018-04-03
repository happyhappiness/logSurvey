#	output
#	untracked
EOF
test_expect_success 'commit --dry-run submodule summary (--amend)' '
	git config status.submodulesummary 10 &&
	git commit --dry-run --amend >output &&
	test_cmp expect output
