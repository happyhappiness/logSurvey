 	git notes show ; test 1 = $?
 '
 
+test_expect_success 'show non-existent notes entry with %N' '
+	for l in A B
+	do
+		echo "$l"
+	done >expect &&
+	git show -s --format='A%n%NB' >output &&
+	test_cmp expect output
+'
+
 test_expect_success 'create notes' '
 	git config core.notesRef refs/notes/commits &&
 	MSG=b4 git notes add &&
