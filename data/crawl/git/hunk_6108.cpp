 '
 
 # NEEDSWORK: not just check return status, but validate the output
-# two tests commented out due to crash and thus unreliable return code
-test_expect_failure 'tree_tag'        'git fast-export tree_tag'
-test_expect_failure 'tree_tag-obj'    'git fast-export tree_tag-obj'
+test_expect_success 'tree_tag'        'git fast-export tree_tag'
+test_expect_success 'tree_tag-obj'    'git fast-export tree_tag-obj'
 test_expect_failure 'tag-obj_tag'     'git fast-export tag-obj_tag'
 test_expect_failure 'tag-obj_tag-obj' 'git fast-export tag-obj_tag-obj'
 