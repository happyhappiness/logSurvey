#	untracked
EOF

test_expect_success C_LOCALE_OUTPUT 'status (2)' '

	git status >output &&
	test_cmp expect output
