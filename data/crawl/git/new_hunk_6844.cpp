virga tua et baculus tuus ipsa me consolata sunt.
EOF

test_expect_success '"diff3 -m" style output (1)' '
	test_must_fail git merge-file -p --diff3 \
		new8.txt new5.txt new9.txt >actual &&
	test_cmp expect actual
'

test_expect_success '"diff3 -m" style output (2)' '
	git config merge.conflictstyle diff3 &&
	test_must_fail git merge-file -p \
		new8.txt new5.txt new9.txt >actual &&
	test_cmp expect actual
'

test_done
