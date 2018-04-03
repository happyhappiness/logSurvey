	grep "^a.1" output
'

test_expect_success 'excluded directory does not override content patterns' '

	git ls-files --others --exclude="one" --exclude="!one/a.1" >output &&
	grep "^one/a.1" output
'

test_expect_success 'negated directory doesn'\''t affect content patterns' '
