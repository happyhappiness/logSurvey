 #	../untracked
 EOF
 
-test_expect_success 'status with relative paths' '
+test_expect_success C_LOCALE_OUTPUT 'status with relative paths' '
 
 	(cd dir1 && git status) >output &&
 	test_cmp expect output
