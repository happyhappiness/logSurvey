 
 '
 
+cat >expect <<EOF
+# On branch master
+# Changes to be committed:
+#   (use "git reset HEAD <file>..." to unstage)
+#
+#	new file:   dir2/added
+#
+# Changed but not updated:
+#   (use "git add <file>..." to update what will be committed)
+#
+#	modified:   dir1/modified
+#
+# Untracked files not listed (use -u option to show untracked files)
+EOF
+test_expect_success 'status -uno' '
+	mkdir dir3 &&
+	: > dir3/untracked1 &&
+	: > dir3/untracked2 &&
+	git status -uno >output &&
+	test_cmp expect output
+'
+
 cat >expect <<EOF
 # On branch master
 # Changes to be committed:
