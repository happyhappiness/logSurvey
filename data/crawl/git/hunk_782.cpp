 	test_cmp expected diff
 '
 
+test_expect_success 'diffs can be colorized' '
+	git reset --hard &&
+
+	# force color even though the test script has no terminal
+	test_config color.ui always &&
+
+	echo content >test &&
+	printf y | git add -p >output 2>&1 &&
+
+	# We do not want to depend on the exact coloring scheme
+	# git uses for diffs, so just check that we saw some kind of color.
+	grep "$(printf "\\033")" output
+'
+
 test_done
