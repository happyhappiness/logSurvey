 
 test_expect_success 'git show-branch (part 4)' '
 	git show-branch --topo-order > show-branch4.output &&
-	cmp show-branch4.expect show-branch4.output
+	test_cmp show-branch4.expect show-branch4.output
 '
 
 test_expect_success 'manual merge' '
