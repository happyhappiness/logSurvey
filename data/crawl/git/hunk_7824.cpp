 	git diff-index --cached --exit-code HEAD
 '
 
+cat > expect << EOF
+file2: needs update
+EOF
+
+test_expect_success '--mixed refreshes the index' '
+	echo 123 >> file2 &&
+	git reset --mixed HEAD > output &&
+	git diff --exit-code expect output
+'
+
 test_done