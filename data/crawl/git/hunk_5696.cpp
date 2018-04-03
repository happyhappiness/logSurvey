 	test_cmp expect one
 '
 
+test_expect_success 'blank at EOF with --whitespace=warn' '
+	{ echo a; echo b; echo c; } >one &&
+	git add one &&
+	echo >>one &&
+	cat one >expect &&
+	git diff -- one >patch &&
+
+	git checkout one &&
+	git apply --whitespace=warn patch 2>error &&
+	test_cmp expect one &&
+	grep "new blank line at EOF" error
+'
+
+test_expect_success 'blank at EOF with --whitespace=error' '
+	{ echo a; echo b; echo c; } >one &&
+	git add one &&
+	cat one >expect &&
+	echo >>one &&
+	git diff -- one >patch &&
+
+	git checkout one &&
+	test_must_fail git apply --whitespace=error patch 2>error &&
+	test_cmp expect one &&
+	grep "new blank line at EOF" error
+'
+
 test_done
