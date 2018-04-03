 EOF
 
 cat > show-branch.expect << EOF
-* [master] Merged "mybranch" changes.
+* [master] Merge work in mybranch
  ! [mybranch] Some work.
 --
+-  [master] Merge work in mybranch
 *+ [mybranch] Some work.
+*  [master^] Some fun.
 EOF
 
 test_expect_success 'git show-branch' '
-	git commit -m "Merged \"mybranch\" changes." -i hello &&
-	git show-branch --topo-order master mybranch > show-branch.output &&
+	git commit -m "Merge work in mybranch" -i hello &&
+	git show-branch --topo-order --more=1 master mybranch \
+		> show-branch.output &&
 	cmp show-branch.expect show-branch.output
 '
 
