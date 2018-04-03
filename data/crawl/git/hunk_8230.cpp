 	)
 '
 
+test_expect_success 'reversing a whitespace introduction' '
+	sed "s/a/a /" < file1 > file1.new &&
+	mv file1.new file1 &&
+	git diff | git apply --reverse --whitespace=error
+'
+
 test_done