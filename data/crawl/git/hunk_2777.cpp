 		cp .git/refs/heads/master .git/refs/heads/broken...ref
 	) &&
 	git -C src push --mirror "file://$top/dest" &&
-	git -C dest branch >output &&
+	git -C dest branch >output 2>error &&
+	! grep -e "broken\.\.\.ref" error &&
 	! grep -e "broken\.\.\.ref" output
 '
 
