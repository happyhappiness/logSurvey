 
 '
 
+test_expect_success 'without -space (attribute)' '
+
+	git config --unset core.whitespace
+	echo "F whitespace=-space" >.gitattributes
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT normal >/dev/null &&
+	grep With error >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
 test_expect_success 'with indent-non-tab only' '
 
+	rm -f .gitattributes
 	git config core.whitespace indent,-trailing,-space
 	git diff --color >output
 	grep "$blue_grep" output >error
