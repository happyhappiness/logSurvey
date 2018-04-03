 		git difftool --dir-diff $symlinks --extcmd ls branch >output &&
 		# "sub" must only exist in "right"
 		# "file" and "file2" must be listed in both "left" and "right"
-		test "1" = $(grep sub output | wc -l) &&
-		test "2" = $(grep file"$" output | wc -l) &&
-		test "2" = $(grep file2 output | wc -l)
+		grep sub output > sub-output &&
+		test_line_count = 1 sub-output &&
+		grep file"$" output >file-output &&
+		test_line_count = 2 file-output &&
+		grep file2 output >file2-output &&
+		test_line_count = 2 file2-output
 	)
 '
 
