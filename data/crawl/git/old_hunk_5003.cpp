test_expect_success 'working --list' \
	'git config --list > output && cmp output expect'

cat > expect << EOF
beta.noindent sillyValue
nextsection.nonewline wow2 for me
