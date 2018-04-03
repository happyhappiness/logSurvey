 
 	check_fsck &&
 
-	test_line_count = 4 .git/logs/refs/heads/master
+	git reflog refs/heads/master >output &&
+	test_line_count = 4 output
 '
 
 test_expect_success rewind '
