 	test_must_fail git notes show HEAD^
 '
 
+test_expect_success 'show notes entry with %N' '
+	for l in A b4 B
+	do
+		echo "$l"
+	done >expect &&
+	git show -s --format='A%n%NB' >output &&
+	test_cmp expect output
+'
+
 cat >expect <<EOF
 d423f8c refs/notes/commits@{0}: notes: Notes added by 'git notes add'
 EOF