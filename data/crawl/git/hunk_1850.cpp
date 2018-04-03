 	key garbage
 	EOF
 	test_must_fail git config --get section.key >actual 2>error &&
-	grep " line 3 " error
+	test_i18ngrep " line 3 " error
 '
 
 test_expect_success 'barf on incomplete section header' '
