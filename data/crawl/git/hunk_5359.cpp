 	(cd sub && git reset --hard) &&
 	echo "content" >sub/new-file &&
 	git status >output &&
-	grep "modified:   sub" output
+	grep "modified:   sub (new commits, untracked content)" output
 '
 
 test_expect_success 'status with untracked file in submodule (porcelain)' '
