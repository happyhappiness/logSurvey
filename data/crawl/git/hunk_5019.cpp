 	git add .
 '
 
-# We have to run from a sub-directory to trigger prune_path
-# Then we finally get to run our --with-tree test
-
 test_expect_success 'git -ls-files --with-tree should succeed from subdir' '
-
-	(cd sub && git ls-files --with-tree=HEAD~1 >../output)
-
+	# We have to run from a sub-directory to trigger prune_path
+	# Then we finally get to run our --with-tree test
+	(
+		cd sub &&
+		git ls-files --with-tree=HEAD~1 >../output
+	)
 '
 
 test_expect_success \
