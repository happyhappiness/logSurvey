no changes added to commit (use "git add" and/or "git commit -a")
EOF
test_expect_success 'status submodule summary (clean submodule): commit' '
	git commit -m "commit submodule" &&
	git config status.submodulesummary 10 &&
	test_must_fail git commit --dry-run >output &&
	test_i18ncmp expect output &&
	git status >output &&
	test_i18ncmp expect output
'

cat >expect <<EOF
