 EOF
 
 
-test_expect_success 'status without relative paths' '
+test_expect_success C_LOCALE_OUTPUT 'status without relative paths' '
 
-	git config status.relativePaths false
+	git config status.relativePaths false &&
+	test_when_finished "git config --unset status.relativePaths" &&
 	(cd dir1 && git status) >output &&
 	test_cmp expect output
 
