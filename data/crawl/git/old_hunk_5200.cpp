?? untracked
EOF

test_expect_success 'status -s (2)' '

	git status -s >output &&
	test_cmp expect output

'

cat >expect <<EOF
# On branch master
# Changes to be committed:
