	grep "^a.1" output
'

test_expect_success 'excluded directory overrides content patterns' '

	git ls-files --others --exclude="one" --exclude="!one/a.1" >output &&
	if grep "^one/a.1" output
	then
		false
	fi
'

test_expect_success 'negated directory doesn'\''t affect content patterns' '

	git ls-files --others --exclude="!one" --exclude="one/a.1" >output &&
	if grep "^one/a.1" output
	then
		false
	fi
'

test_expect_success 'subdirectory ignore (setup)' '
	mkdir -p top/l1/l2 &&
	(