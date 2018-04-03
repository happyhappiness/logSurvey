	test_cmp expect output
'

cat > expect_list << EOF
c18dc024e14f08d18d14eea0d747ff692d66d6a3 1584215f1d29c65e99c6c6848626553fdd07fd75
c9c6af7f78bc47490dbf3e822cf2f3c24d4b9061 268048bfb8a1fb38e703baceb8ab235421bf80c5
4b6ad22357cc8a1296720574b8d2fbc22fab0671 bd1753200303d0a0344be813e504253b3d98e74d
EOF

test_expect_success '"git notes list" does not expand to "git notes list HEAD"' '
	git notes list > output &&
	test_cmp expect_list output
'

test_expect_success 'appending empty string does not change existing note' '
	git notes append -m "" &&
	git notes show > output &&