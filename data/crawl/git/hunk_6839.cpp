 
 '
 
+test_expect_success 'do not color trailing cr in context' '
+	git config --unset core.whitespace
+	rm -f .gitattributes &&
+	echo AAAQ | tr Q "\015" >G &&
+	git add G &&
+	echo BBBQ | tr Q "\015" >>G
+	git diff --color G | tr "\015" Q >output &&
+	grep "BBB.*${blue_grep}Q" output &&
+	grep "AAA.*\[mQ" output
+
+'
+
 test_done