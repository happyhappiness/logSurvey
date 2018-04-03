	test_cmp expect output
'

cat > expect << EOF
beta.noindent
nextsection.nonewline
EOF

test_expect_success '--name-only --get-regexp' '
	git config --name-only --get-regexp in >output &&
	test_cmp expect output
'

cat > expect << EOF
wow2 for me
wow4 for you