 '
 
 test_expect_success PERL 'difftool -d' '
-	diff=$(git difftool -d --extcmd ls branch) &&
-	echo "$diff" | stdin_contains sub &&
-	echo "$diff" | stdin_contains file
+	git difftool -d --extcmd ls branch >output &&
+	stdin_contains sub <output &&
+	stdin_contains file <output
 '
 
 test_expect_success PERL 'difftool --dir-diff' '
-	diff=$(git difftool --dir-diff --extcmd ls branch) &&
-	echo "$diff" | stdin_contains sub &&
-	echo "$diff" | stdin_contains file
+	git difftool --dir-diff --extcmd ls branch >output &&
+	stdin_contains sub <output &&
+	stdin_contains file <output
 '
 
 test_expect_success PERL 'difftool --dir-diff ignores --prompt' '
-	diff=$(git difftool --dir-diff --prompt --extcmd ls branch) &&
-	echo "$diff" | stdin_contains sub &&
-	echo "$diff" | stdin_contains file
+	git difftool --dir-diff --prompt --extcmd ls branch >output &&
+	stdin_contains sub <output &&
+	stdin_contains file <output
 '
 
 test_expect_success PERL 'difftool --dir-diff from subdirectory' '
 	(
 		cd sub &&
-		diff=$(git difftool --dir-diff --extcmd ls branch) &&
-		echo "$diff" | stdin_contains sub &&
-		echo "$diff" | stdin_contains file
+		git difftool --dir-diff --extcmd ls branch >output &&
+		stdin_contains sub <output &&
+		stdin_contains file <output
 	)
 '
 