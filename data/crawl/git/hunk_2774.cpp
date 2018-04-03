 test_expect_success 'git branch cannot create a badly named ref' '
 	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
 	test_must_fail git branch broken...ref &&
-	git branch >output &&
+	git branch >output 2>error &&
+	! grep -e "broken\.\.\.ref" error &&
 	! grep -e "broken\.\.\.ref" output
 '
 
