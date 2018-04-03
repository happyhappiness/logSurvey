#	untracked
EOF

test_expect_success 'status (2)' '
	git status >output &&
	test_i18ncmp expect output
'

cat >expect <<\EOF
