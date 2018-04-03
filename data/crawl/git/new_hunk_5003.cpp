test_expect_success 'working --list' \
	'git config --list > output && cmp output expect'

cat > expect << EOF
EOF

test_expect_success '--list without repo produces empty output' '
	git --git-dir=nonexistent config --list >output &&
	test_cmp expect output
'

cat > expect << EOF
beta.noindent sillyValue
nextsection.nonewline wow2 for me
