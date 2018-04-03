 ?? untracked
 EOF
 
-test_expect_success 'status -s (2)' '
+test_expect_success 'status -s' '
 
 	git status -s >output &&
 	test_cmp expect output
 
 '
 
+cat >expect <<\EOF
+## master
+ M dir1/modified
+A  dir2/added
+?? dir1/untracked
+?? dir2/modified
+?? dir2/untracked
+?? expect
+?? output
+?? untracked
+EOF
+
+test_expect_success 'status -s -b' '
+
+	git status -s -b >output &&
+	test_cmp expect output
+
+'
+
 cat >expect <<EOF
 # On branch master
 # Changes to be committed:
