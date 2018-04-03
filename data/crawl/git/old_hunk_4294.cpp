#	untracked
EOF

git config advice.statusHints false

test_expect_success C_LOCALE_OUTPUT 'status (advice.statusHints false)' '

	git status >output &&
	test_cmp expect output

'

git config --unset advice.statusHints

cat >expect <<\EOF
 M dir1/modified
A  dir2/added
