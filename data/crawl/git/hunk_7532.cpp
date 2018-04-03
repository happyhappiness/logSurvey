 	grep Eight error >/dev/null &&
 	grep HT normal >/dev/null &&
 	grep With normal >/dev/null &&
+	grep Return normal >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_expect_success 'with cr-at-eol' '
+
+	rm -f .gitattributes
+	git config core.whitespace cr-at-eol
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT error >/dev/null &&
+	grep With error >/dev/null &&
+	grep Return normal >/dev/null &&
+	grep No normal >/dev/null
+
+'
+
+test_expect_success 'with cr-at-eol (attribute)' '
+
+	git config --unset core.whitespace
+	echo "F whitespace=trailing,cr-at-eol" >.gitattributes
+	git diff --color >output
+	grep "$blue_grep" output >error
+	grep -v "$blue_grep" output >normal
+
+	grep Eight normal >/dev/null &&
+	grep HT error >/dev/null &&
+	grep With error >/dev/null &&
+	grep Return normal >/dev/null &&
 	grep No normal >/dev/null
 
 '
