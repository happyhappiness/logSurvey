 :100644 100644 4268632... 55d3a52... M	ba
 EXPECT_END
 
-test_expect_success \
-    'L: verify internal tree sorting' \
-	'git fast-import <input &&
-	 git diff-tree --abbrev --raw L^ L >output &&
-	 test_cmp expect output'
+test_expect_success 'L: verify internal tree sorting' '
+	git fast-import <input &&
+	git diff-tree --abbrev --raw L^ L >output &&
+	test_cmp expect output
+'
 
 cat >input <<INPUT_END
 blob
