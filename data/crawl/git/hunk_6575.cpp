 
 '
 
+test_expect_success 'negated exclude matches can override previous ones' '
+
+	git ls-files --others --exclude="a.*" --exclude="!a.1" >output &&
+	grep "^a.1" output
+'
+
 test_done