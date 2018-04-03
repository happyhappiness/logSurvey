 
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
+# Untracked files:
+#   (use "git add <file>..." to include in what will be committed)
+#
+#	dir1/untracked
+#	dir2/modified
+#	dir2/untracked
+#	dir3/
+#	expect
+#	output
+#	untracked
+EOF
+test_expect_success 'status -unormal' '
+	mkdir dir3 &&
+	: > dir3/untracked1 &&
+	: > dir3/untracked2 &&
+	git status -unormal >output &&
+	test_cmp expect output
+'
+
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
+# Untracked files:
+#   (use "git add <file>..." to include in what will be committed)
+#
+#	dir1/untracked
+#	dir2/modified
+#	dir2/untracked
+#	dir3/untracked1
+#	dir3/untracked2
+#	expect
+#	output
+#	untracked
+EOF
+test_expect_success 'status -uall' '
+	git status -uall >output &&
+	rm -rf dir3 &&
+	test_cmp expect output
+'
+
 cat > expect << \EOF
 # On branch master
 # Changes to be committed:
