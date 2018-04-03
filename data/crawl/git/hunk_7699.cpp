 
 '
 
+test_expect_success 'without -trail (attribute)' '
+
+	git config --unset core.whitespace
+	echo "F whitespace=-trail" >.gitattributes
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT error >/dev/null &&
+	grep With normal >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
 test_expect_success 'without -space' '
 
+	rm -f .gitattributes
 	git config core.whitespace -space
 	git diff --color >output
 	grep "$blue_grep" output >error
