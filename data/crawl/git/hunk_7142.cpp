 test_expect_success 'status (2)' '
 
 	git status > output &&
-	git diff expect output
+	test_cmp expect output
 
 '
 
