	test "$(git notes list HEAD^)" = "$(git notes list HEAD~3)"
'

test_done
