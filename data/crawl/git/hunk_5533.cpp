 
 test_expect_success 'git show-branch (part 2)' '
 	git show-branch --topo-order master mybranch > show-branch2.output &&
-	cmp show-branch2.expect show-branch2.output
+	test_cmp show-branch2.expect show-branch2.output
 '
 
 cat > show-branch3.expect << EOF
