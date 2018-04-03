 
 '
 
+cat >expect <<\EOF
+# On branch master
+# Changes to be committed:
+#	new file:   dir2/added
+#
+# Changed but not updated:
+#	modified:   dir1/modified
+#
+# Untracked files:
+#	dir1/untracked
+#	dir2/modified
+#	dir2/untracked
+#	expect
+#	output
+#	untracked
+EOF
+
+git config advice.statusHints false
+
+test_expect_success 'status (advice.statusHints false)' '
+
+	git status >output &&
+	test_cmp expect output
+
+'
+
+git config --unset advice.statusHints
+
 cat >expect <<\EOF
  M dir1/modified
 A  dir2/added
