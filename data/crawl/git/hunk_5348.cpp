 	git show HEAD~2 | grep "C changed"
 '
 
+test_expect_success 'rebase -i can copy notes' '
+	git config notes.rewrite.rebase true &&
+	git config notes.rewriteRef "refs/notes/*" &&
+	test_commit n1 &&
+	test_commit n2 &&
+	test_commit n3 &&
+	git notes add -m"a note" n3 &&
+	git rebase --onto n1 n2 &&
+	test "a note" = "$(git notes show HEAD)"
+'
+
+cat >expect <<EOF
+an earlier note
+a note
+EOF
+
+test_expect_success 'rebase -i can copy notes over a fixup' '
+	git reset --hard n3 &&
+	git notes add -m"an earlier note" n2 &&
+	GIT_NOTES_REWRITE_MODE=concatenate FAKE_LINES="1 fixup 2" git rebase -i n1 &&
+	git notes show > output &&
+	test_cmp expect output
+'
+
 test_done