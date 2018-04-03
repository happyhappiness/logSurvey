 	test_must_fail git notes show HEAD^
 '
 
+cat >expect <<EOF
+d423f8c refs/notes/commits@{0}: notes: Notes added by 'git notes add'
+EOF
+
+test_expect_failure 'create reflog entry' '
+	git reflog show refs/notes/commits >output &&
+	test_cmp expect output
+'
+
 test_expect_success 'edit existing notes' '
 	MSG=b3 git notes edit &&
 	test ! -f .git/NOTES_EDITMSG &&