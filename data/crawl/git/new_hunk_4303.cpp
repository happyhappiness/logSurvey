#	output
#	untracked
EOF
test_expect_success 'status submodule summary is disabled by default' '
	git status >output &&
	test_i18ncmp expect output
'

# we expect the same as the previous test
test_expect_success 'status --untracked-files=all does not show submodule' '
	git status --untracked-files=all >output &&
	test_i18ncmp expect output
'

cat >expect <<EOF
