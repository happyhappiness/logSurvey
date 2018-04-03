 
 test_expect_success 'status -s without relative paths' '
 
+	git config status.relativePaths false &&
+	test_when_finished "git config --unset status.relativePaths" &&
 	(cd dir1 && git status -s) >output &&
 	test_cmp expect output
 
