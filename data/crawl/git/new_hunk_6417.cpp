	'git config --bool emptyvalue.variable > output &&
	 cmp output expect'

test_expect_success 'no arguments, but no crash' '
	test_must_fail git config >output 2>&1 &&
	grep usage output
'

cat > .git/config << EOF
[a.b]
