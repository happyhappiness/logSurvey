 git config --unset color.status
 git config --unset color.ui
 
+test_expect_success 'status --porcelain ignores -b' '
+
+	git status --porcelain -b >output &&
+	test_cmp expect output
+
+'
+
 cat >expect <<\EOF
 # On branch master
 # Changes to be committed: