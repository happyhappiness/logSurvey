#	<BLUE>untracked<RESET>
EOF

test_expect_success 'status with color.ui' '
	git config color.ui always &&
	test_when_finished "git config --unset color.ui" &&
	git status | test_decode_color >output &&
	test_i18ncmp expect output
'

test_expect_success 'status with color.status' '
	git config color.status always &&
	test_when_finished "git config --unset color.status" &&
	git status | test_decode_color >output &&
	test_i18ncmp expect output
'

cat >expect <<\EOF
