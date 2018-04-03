c9c6af7f78bc47490dbf3e822cf2f3c24d4b9061 268048bfb8a1fb38e703baceb8ab235421bf80c5
EOF

test_expect_success 'removing non-existing note should not create new commit' '
	git rev-parse --verify refs/notes/commits > before_commit &&
	test_must_fail git notes remove HEAD^ &&
	git rev-parse --verify refs/notes/commits > after_commit &&
	test_cmp before_commit after_commit
'

test_expect_success 'list notes with "git notes list"' '
	git notes list > output &&
	test_cmp expect output