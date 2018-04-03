 EOF
 test_expect_success 'status of partial commit excluding new file in index' '
 	git status dir1/modified >output &&
-	diff -u expect output
+	test_cmp expect output
 '
 
 test_done
