 		git difftool --dir-diff $symlinks --extcmd ls branch -- .>output &&
 		# "sub" only exists in "right"
 		# "file" and "file2" must not be listed
-		test "1" = $(grep sub output | wc -l) &&
-		test "0" = $(grep file output | wc -l)
+		grep sub output >sub-output &&
+		test_line_count = 1 sub-output &&
+		! grep file output
 	)
 '
 
