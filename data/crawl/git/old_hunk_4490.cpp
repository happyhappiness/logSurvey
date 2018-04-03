no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success "--ignore-submodules=all suppresses submodule summary" '
	git status --ignore-submodules=all > output &&
	test_cmp expect output
'
