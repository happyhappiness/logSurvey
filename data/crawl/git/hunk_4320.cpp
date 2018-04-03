 M	file2
 EOF
 
-test_expect_success C_LOCALE_OUTPUT '--mixed refreshes the index' '
+test_expect_success '--mixed refreshes the index' '
 	echo 123 >> file2 &&
 	git reset --mixed HEAD > output &&
-	test_cmp expect output
+	test_i18ncmp expect output
 '
 
 test_expect_success 'disambiguation (1)' '
