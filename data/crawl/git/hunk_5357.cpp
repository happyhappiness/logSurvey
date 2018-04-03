 	(cd sub && git reset --hard) &&
 	echo "changed" >sub/foo &&
 	git status >output &&
-	grep "modified:   sub" output
+	grep "modified:   sub (new commits, modified content)" output
 '
 
 test_expect_success 'status with modified file in submodule (porcelain)' '
