 	grep "^a.1" output
 '
 
-test_expect_success 'excluded directory does not override content patterns' '
+test_expect_success 'excluded directory overrides content patterns' '
 
 	git ls-files --others --exclude="one" --exclude="!one/a.1" >output &&
-	grep "^one/a.1" output
+	if grep "^one/a.1" output
+	then
+		false
+	fi
 '
 
 test_expect_success 'negated directory doesn'\''t affect content patterns' '
