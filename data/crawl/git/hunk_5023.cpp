 
 # We have to run from a sub-directory to trigger prune_path
 # Then we finally get to run our --with-tree test
-cd sub
 
 test_expect_success 'git -ls-files --with-tree should succeed from subdir' '
 
-	git ls-files --with-tree=HEAD~1 >../output
+	(cd sub && git ls-files --with-tree=HEAD~1 >../output)
 
 '
 
-cd ..
 test_expect_success \
     'git -ls-files --with-tree should add entries from named tree.' \
     'test_cmp expected output'
