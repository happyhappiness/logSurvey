 	test_cmp expect output
 '
 
+cat >expect <<EOF
+# On branch master
+# Changes to be committed:
+#	new file:   dir2/added
+#
+# Changed but not updated:
+#	modified:   dir1/modified
+#
+# Untracked files not listed (use -u option to show untracked files)
+EOF
+git config advice.statusHints false
+test_expect_success 'status -uno (advice.statusHints false)' '
+	git status -uno >output &&
+	test_cmp expect output
+'
+git config --unset advice.statusHints
+
 cat >expect << EOF
  M dir1/modified
 A  dir2/added