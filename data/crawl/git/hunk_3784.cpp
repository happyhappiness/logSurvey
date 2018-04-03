 	stdin_contains file <output
 '
 
+test_expect_success PERL 'difftool --dir-diff ignores --prompt' '
+	git difftool --dir-diff --prompt --extcmd ls branch >output &&
+	stdin_contains sub <output &&
+	stdin_contains file <output
+'
+
+test_expect_success PERL 'difftool --dir-diff from subdirectory' '
+	(
+		cd sub &&
+		git difftool --dir-diff --extcmd ls branch >output &&
+		stdin_contains sub <output &&
+		stdin_contains file <output
+	)
+'
+
 write_script .git/CHECK_SYMLINKS <<\EOF
 for f in file file2 sub/sub
 do
