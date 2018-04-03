	'git config --bool emptyvalue.variable > output &&
	 cmp output expect'

git config > output 2>&1

test_expect_success 'no arguments, but no crash' \
	"test $? = 129 && grep usage output"

cat > .git/config << EOF
[a.b]
