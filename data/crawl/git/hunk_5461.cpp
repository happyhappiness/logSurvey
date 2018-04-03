 
 	rm -f .gitattributes
 	git config core.whitespace cr-at-eol
-	git diff --color >output
-	grep "$blue_grep" output >error
-	grep -v "$blue_grep" output >normal
+	prepare_output
 
 	grep Eight normal >/dev/null &&
 	grep HT error >/dev/null &&
