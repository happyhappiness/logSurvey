 '
 
 test_expect_success PERL 'say no to the first file' '
-	diff=$( (echo n; echo) | git difftool -x cat branch ) &&
-
-	echo "$diff" | stdin_contains m2 &&
-	echo "$diff" | stdin_contains br2 &&
-	echo "$diff" | stdin_doesnot_contain master &&
-	echo "$diff" | stdin_doesnot_contain branch
+	(echo n && echo) >input &&
+	git difftool -x cat branch <input >output &&
+	stdin_contains m2 <output &&
+	stdin_contains br2 <output &&
+	stdin_doesnot_contain master <output &&
+	stdin_doesnot_contain branch <output
 '
 
 test_expect_success PERL 'say no to the second file' '
-	diff=$( (echo; echo n) | git difftool -x cat branch ) &&
-
-	echo "$diff" | stdin_contains master &&
-	echo "$diff" | stdin_contains branch &&
-	echo "$diff" | stdin_doesnot_contain m2 &&
-	echo "$diff" | stdin_doesnot_contain br2
+	(echo && echo n) >input &&
+	git difftool -x cat branch <input >output &&
+	stdin_contains master <output &&
+	stdin_contains branch  <output &&
+	stdin_doesnot_contain m2 <output &&
+	stdin_doesnot_contain br2 <output
 '
 
 test_expect_success PERL 'difftool --tool-help' '
-	tool_help=$(git difftool --tool-help) &&
-	echo "$tool_help" | stdin_contains tool
+	git difftool --tool-help >output &&
+	stdin_contains tool <output
 '
 
 test_expect_success PERL 'setup change in subdirectory' '
