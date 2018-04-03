 	grep "new blank line at EOF" error
 '
 
+test_expect_success 'blank but not empty at EOF' '
+	{ echo a; echo b; echo c; } >one &&
+	git add one &&
+	echo "   " >>one &&
+	cat one >expect &&
+	git diff -- one >patch &&
+
+	git checkout one &&
+	git apply --whitespace=warn patch 2>error &&
+	test_cmp expect one &&
+	grep "new blank line at EOF" error
+'
+
 test_done