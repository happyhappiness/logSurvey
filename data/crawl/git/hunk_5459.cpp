 
 	rm -f .gitattributes
 	git config core.whitespace indent,-trailing,-space
-	git diff --color >output
-	grep "$blue_grep" output >error
-	grep -v "$blue_grep" output >normal
+	prepare_output
 
 	grep Eight error >/dev/null &&
 	grep HT normal >/dev/null &&
