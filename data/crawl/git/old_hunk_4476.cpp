#	<BLUE>untracked<RESET>
EOF

test_expect_success 'status with color.ui' '

	git config color.ui always &&
	git status | test_decode_color >output &&
	test_cmp expect output

'

test_expect_success 'status with color.status' '

	git config --unset color.ui &&
	git config color.status always &&
	git status | test_decode_color >output &&
	test_cmp expect output

