#	../untracked
EOF

test_expect_success 'status with relative paths' '
	(cd dir1 && git status) >output &&
	test_i18ncmp expect output
'

cat >expect <<\EOF
