#	untracked
EOF

test_expect_success C_LOCALE_OUTPUT '--ignore-submodules=untracked suppresses submodules with untracked content' '
	echo modified > sm/untracked &&
	git status --ignore-submodules=untracked > output &&
	test_cmp expect output
'

test_expect_success C_LOCALE_OUTPUT '.gitmodules ignore=untracked suppresses submodules with untracked content' '
	git config diff.ignoreSubmodules dirty &&
	git status >output &&
	test_cmp expect output &&
