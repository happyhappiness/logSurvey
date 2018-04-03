 
 '
 
+test_expect_success 'trailing empty lines (1)' '
+
+	rm -f .gitattributes &&
+	test_must_fail git diff --check >output &&
+	grep "ends with blank lines." output &&
+	grep "trailing whitespace" output
+
+'
+
+test_expect_success 'trailing empty lines (2)' '
+
+	echo "F -whitespace" >.gitattributes &&
+	git diff --check >output &&
+	! test -s output
+
+'
+
 test_done