 	test_i18ncmp expect actual
 '
 
+test_expect_success 'rm empty string should invoke warning' '
+	git rm -rf "" 2>output &&
+	test_i18ngrep "warning: empty strings" output
+'
+
 test_done
