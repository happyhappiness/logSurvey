 	'
 
 	test_expect_success 'non-fast-forward push shows help message' '
-		test_i18ngrep "To prevent you from losing history, non-fast-forward updates were rejected" output
+		test_i18ngrep "Updates were rejected because" output
 	'
 }
