 
 	git config --unset core.whitespace
 	echo "F whitespace=-space" >.gitattributes
-	git diff --color >output
-	grep "$blue_grep" output >error
-	grep -v "$blue_grep" output >normal
+	prepare_output
 
 	grep Eight normal >/dev/null &&
 	grep HT normal >/dev/null &&
