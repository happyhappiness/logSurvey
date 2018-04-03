 	EOF
 '
 
+test_expect_success 'status with added and untracked file in submodule' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	echo "content" >sub/new-file &&
+	git status >output &&
+	grep "modified:   sub (modified content, untracked content)" output
+'
+
+test_expect_success 'status with added and untracked file in submodule (porcelain)' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	echo "content" >sub/new-file &&
+	git status --porcelain >output &&
+	diff output - <<-\EOF
+	 M sub
+	EOF
+'
+
+test_expect_success 'status with modified file in modified submodule' '
+	(cd sub && git reset --hard) &&
+	rm sub/new-file &&
+	(cd sub && echo "next change" >foo && git commit -m "next change" foo) &&
+	echo "changed" >sub/foo &&
+	git status >output &&
+	grep "modified:   sub (new commits, modified content)" output
+'
+
+test_expect_success 'status with modified file in modified submodule (porcelain)' '
+	(cd sub && git reset --hard) &&
+	echo "changed" >sub/foo &&
+	git status --porcelain >output &&
+	diff output - <<-\EOF
+	 M sub
+	EOF
+'
+
+test_expect_success 'status with added file in modified submodule' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	git status >output &&
+	grep "modified:   sub (new commits, modified content)" output
+'
+
+test_expect_success 'status with added file in modified submodule (porcelain)' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	git status --porcelain >output &&
+	diff output - <<-\EOF
+	 M sub
+	EOF
+'
+
+test_expect_success 'status with untracked file in modified submodule' '
+	(cd sub && git reset --hard) &&
+	echo "content" >sub/new-file &&
+	git status >output &&
+	grep "modified:   sub (new commits, untracked content)" output
+'
+
+test_expect_success 'status with untracked file in modified submodule (porcelain)' '
+	git status --porcelain >output &&
+	diff output - <<-\EOF
+	 M sub
+	EOF
+'
+
+test_expect_success 'status with added and untracked file in modified submodule' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	echo "content" >sub/new-file &&
+	git status >output &&
+	grep "modified:   sub (new commits, modified content, untracked content)" output
+'
+
+test_expect_success 'status with added and untracked file in modified submodule (porcelain)' '
+	(cd sub && git reset --hard && echo >foo && git add foo) &&
+	echo "content" >sub/new-file &&
+	git status --porcelain >output &&
+	diff output - <<-\EOF
+	 M sub
+	EOF
+'
+
 test_expect_success 'rm submodule contents' '
 	rm -rf sub/* sub/.git
 '