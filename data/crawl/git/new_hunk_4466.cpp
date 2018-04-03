	git add dir2/added
'

test_expect_success C_LOCALE_OUTPUT 'status (1)' '

	grep "use \"git rm --cached <file>\.\.\.\" to unstage" output

