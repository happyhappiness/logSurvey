 	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
 	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
 	git update-ref -d refs/heads/broken...ref &&
-	git branch >output &&
+	git branch >output 2>error &&
+	! grep -e "broken\.\.\.ref" error &&
 	! grep -e "broken\.\.\.ref" output
 '
 
