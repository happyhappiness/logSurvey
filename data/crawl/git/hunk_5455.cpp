 test_expect_success 'without -trail' '
 
 	git config core.whitespace -trail
-	git diff --color >output
-	grep "$blue_grep" output >error
-	grep -v "$blue_grep" output >normal
+	prepare_output
 
 	grep Eight normal >/dev/null &&
 	grep HT error >/dev/null &&
