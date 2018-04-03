 #	untracked
 EOF
 
-test_expect_success C_LOCALE_OUTPUT 'status (2)' '
-
+test_expect_success 'status (2)' '
 	git status >output &&
-	test_cmp expect output
-
+	test_i18ncmp expect output
 '
 
 cat >expect <<\EOF
