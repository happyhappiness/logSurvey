 -- [master] Merged "mybranch" changes.
 EOF
 
-git show-branch --topo-order master mybranch > show-branch2.output
-test_expect_success 'git show-branch' 'cmp show-branch2.expect show-branch2.output'
-
-# TODO: test git fetch
-
-# TODO: test git push
+test_expect_success 'git show-branch (part 2)' '
+	git show-branch --topo-order master mybranch > show-branch2.output &&
+	cmp show-branch2.expect show-branch2.output
+'
 
 test_expect_success 'git repack' 'git repack'
 test_expect_success 'git prune-packed' 'git prune-packed'
 test_expect_success '-> only packed objects' '
-	! find -type f .git/objects/[0-9a-f][0-9a-f]
+	git prune && # Remove conflict marked blobs
+	! find .git/objects/[0-9a-f][0-9a-f] -type f
 '
 
 test_done