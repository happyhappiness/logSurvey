 	git bisect next
 '
 
+test_expect_success 'bisect reset: back in the master branch' '
+	git bisect reset &&
+	echo "* master" > branch.expect &&
+	git branch > branch.output &&
+	cmp branch.expect branch.output
+'
+
+test_expect_success 'bisect reset: back in another branch' '
+	git checkout -b other &&
+	git bisect start &&
+	git bisect good $HASH1 &&
+	git bisect bad $HASH3 &&
+	git bisect reset &&
+	echo "  master" > branch.expect &&
+	echo "* other" >> branch.expect &&
+	git branch > branch.output &&
+	cmp branch.expect branch.output
+'
+
+test_expect_success 'bisect reset when not bisecting' '
+	git bisect reset &&
+	git branch > branch.output &&
+	cmp branch.expect branch.output
+'
+
 test_expect_success 'bisect reset removes packed refs' '
 	git bisect reset &&
 	git bisect start &&
