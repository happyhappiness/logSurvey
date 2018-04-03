 
 test_expect_success '"git log :" should be ambiguous' '
 	test_must_fail git log : 2>error &&
-	grep ambiguous error
+	test_i18ngrep ambiguous error
 '
 
 test_expect_success 'git log -- :' '