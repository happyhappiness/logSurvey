 test_expect_success 'status with added file in submodule' '
 	(cd sub && git reset --hard && echo >foo && git add foo) &&
 	git status >output &&
-	grep "modified:   sub (new commits, modified content)" output
+	grep "modified:   sub (modified content)" output
 '
 
 test_expect_success 'status with added file in submodule (porcelain)' '
