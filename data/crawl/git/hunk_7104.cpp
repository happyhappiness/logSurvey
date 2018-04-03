 #	untracked
 EOF
 test_expect_success 'status -unormal' '
-	mkdir dir3 &&
-	: > dir3/untracked1 &&
-	: > dir3/untracked2 &&
 	git status -unormal >output &&
 	test_cmp expect output
 '
