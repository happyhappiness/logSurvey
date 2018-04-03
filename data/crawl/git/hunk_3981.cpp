 #
 # and 'side' should be the last branch
 
-test_rev_equivalent () {
-
-	git rev-parse "$1" > expect &&
-	git rev-parse "$2" > output &&
-	test_cmp expect output
-
-}
-
 test_expect_success '@{-1} works' '
-	test_rev_equivalent side @{-1}
+	test_cmp_rev side @{-1}
 '
 
 test_expect_success '@{-1}~2 works' '
-	test_rev_equivalent side~2 @{-1}~2
+	test_cmp_rev side~2 @{-1}~2
 '
 
 test_expect_success '@{-1}^2 works' '
-	test_rev_equivalent side^2 @{-1}^2
+	test_cmp_rev side^2 @{-1}^2
 '
 
 test_expect_success '@{-1}@{1} works' '
-	test_rev_equivalent side@{1} @{-1}@{1}
+	test_cmp_rev side@{1} @{-1}@{1}
 '
 
 test_expect_success '@{-2} works' '
-	test_rev_equivalent master @{-2}
+	test_cmp_rev master @{-2}
 '
 
 test_expect_success '@{-3} fails' '
