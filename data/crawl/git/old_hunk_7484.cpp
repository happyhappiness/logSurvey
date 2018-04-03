#	untracked
EOF

test_expect_success 'status' '

	git status > output &&
	git diff expect output
