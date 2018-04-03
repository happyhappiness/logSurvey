	git notes show ; test 1 = $?
'

test_expect_success 'create notes' '
	git config core.notesRef refs/notes/commits &&
	MSG=b4 git notes add &&
