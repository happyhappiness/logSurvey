	test_must_fail git notes show HEAD^
'

test_expect_success 'edit existing notes' '
	MSG=b3 git notes edit &&
	test ! -f .git/NOTES_EDITMSG &&