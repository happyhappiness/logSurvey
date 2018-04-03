c9c6af7f78bc47490dbf3e822cf2f3c24d4b9061 268048bfb8a1fb38e703baceb8ab235421bf80c5
EOF

test_expect_success 'list notes with "git notes list"' '
	git notes list > output &&
	test_cmp expect output