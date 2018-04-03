 	EOF
 '
 
-test_expect_success C_LOCALE_OUTPUT 'status with modified file in modified submodule' '
+test_expect_success 'status with modified file in modified submodule' '
 	(cd sub && git reset --hard) &&
 	rm sub/new-file &&
 	(cd sub && echo "next change" >foo && git commit -m "next change" foo) &&
 	echo "changed" >sub/foo &&
 	git status >output &&
-	grep "modified:   sub (new commits, modified content)" output
+	test_i18ngrep "modified:   sub (new commits, modified content)" output
 '
 
 test_expect_success 'status with modified file in modified submodule (porcelain)' '
