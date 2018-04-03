 	test "$(git notes list HEAD^)" = "$(git notes list HEAD~3)"
 '
 
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+commit be28d8b4d9951ad940d229ee3b0b9ee3b1ec273d
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:26:13 2005 -0700
+
+    14th
+EOF
+
+test_expect_success 'git notes copy --for-rewrite (unconfigured)' '
+	test_commit 14th &&
+	test_commit 15th &&
+	(echo $(git rev-parse HEAD~3) $(git rev-parse HEAD^); \
+	echo $(git rev-parse HEAD~2) $(git rev-parse HEAD)) |
+	git notes copy --for-rewrite=foo &&
+	git log -2 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    yet another note
+$whitespace
+    yet another note
+
+commit be28d8b4d9951ad940d229ee3b0b9ee3b1ec273d
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:26:13 2005 -0700
+
+    14th
+
+Notes (other):
+    other note
+$whitespace
+    yet another note
+EOF
+
+test_expect_success 'git notes copy --for-rewrite (enabled)' '
+	git config notes.rewriteMode overwrite &&
+	git config notes.rewriteRef "refs/notes/*" &&
+	(echo $(git rev-parse HEAD~3) $(git rev-parse HEAD^); \
+	echo $(git rev-parse HEAD~2) $(git rev-parse HEAD)) |
+	git notes copy --for-rewrite=foo &&
+	git log -2 > output &&
+	test_cmp expect output
+'
+
+test_expect_success 'git notes copy --for-rewrite (disabled)' '
+	git config notes.rewrite.bar false &&
+	echo $(git rev-parse HEAD~3) $(git rev-parse HEAD) |
+	git notes copy --for-rewrite=bar &&
+	git log -2 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    a fresh note
+EOF
+
+test_expect_success 'git notes copy --for-rewrite (overwrite)' '
+	git notes add -f -m"a fresh note" HEAD^ &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+test_expect_success 'git notes copy --for-rewrite (ignore)' '
+	git config notes.rewriteMode ignore &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    a fresh note
+    another fresh note
+EOF
+
+test_expect_success 'git notes copy --for-rewrite (append)' '
+	git notes add -f -m"another fresh note" HEAD^ &&
+	git config notes.rewriteMode concatenate &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    a fresh note
+    another fresh note
+    append 1
+    append 2
+EOF
+
+test_expect_success 'git notes copy --for-rewrite (append two to one)' '
+	git notes add -f -m"append 1" HEAD^ &&
+	git notes add -f -m"append 2" HEAD^^ &&
+	(echo $(git rev-parse HEAD^) $(git rev-parse HEAD);
+	echo $(git rev-parse HEAD^^) $(git rev-parse HEAD)) |
+	git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+test_expect_success 'git notes copy --for-rewrite (append empty)' '
+	git notes remove HEAD^ &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    replacement note 1
+EOF
+
+test_expect_success 'GIT_NOTES_REWRITE_MODE works' '
+	git notes add -f -m"replacement note 1" HEAD^ &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	GIT_NOTES_REWRITE_MODE=overwrite git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+cat > expect << EOF
+commit 37a0d4cba38afef96ba54a3ea567e6dac575700b
+Author: A U Thor <author@example.com>
+Date:   Thu Apr 7 15:27:13 2005 -0700
+
+    15th
+
+Notes (other):
+    replacement note 2
+EOF
+
+test_expect_success 'GIT_NOTES_REWRITE_REF works' '
+	git config notes.rewriteMode overwrite &&
+	git notes add -f -m"replacement note 2" HEAD^ &&
+	git config --unset-all notes.rewriteRef &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	GIT_NOTES_REWRITE_REF=refs/notes/commits:refs/notes/other \
+		git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
+
+test_expect_success 'GIT_NOTES_REWRITE_REF overrides config' '
+	git config notes.rewriteRef refs/notes/other &&
+	git notes add -f -m"replacement note 3" HEAD^ &&
+	echo $(git rev-parse HEAD^) $(git rev-parse HEAD) |
+	GIT_NOTES_REWRITE_REF= git notes copy --for-rewrite=foo &&
+	git log -1 > output &&
+	test_cmp expect output
+'
 test_done
