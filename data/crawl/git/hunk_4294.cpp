 #	untracked
 EOF
 
-git config advice.statusHints false
-
-test_expect_success C_LOCALE_OUTPUT 'status (advice.statusHints false)' '
-
+test_expect_success 'status (advice.statusHints false)' '
+	test_when_finished "git config --unset advice.statusHints" &&
+	git config advice.statusHints false &&
 	git status >output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 
 '
 
-git config --unset advice.statusHints
-
 cat >expect <<\EOF
  M dir1/modified
 A  dir2/added
