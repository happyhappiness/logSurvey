no changes added to commit (use "git add" and/or "git commit -a")
EOF

test_expect_success "--ignore-submodules=all suppresses submodule summary" '
	git status --ignore-submodules=all > output &&
	test_i18ncmp expect output
'

test_expect_failure '.gitmodules ignore=all suppresses submodule summary' '