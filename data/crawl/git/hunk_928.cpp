 	grep file output
 '
 
-run_dir_diff_test 'difftool --dir-diff from subdirectory' '
+run_dir_diff_test 'difftool --dir-diff branch from subdirectory' '
 	(
 		cd sub &&
 		git difftool --dir-diff $symlinks --extcmd ls branch >output &&
-		grep sub output &&
-		grep file output
+		# "sub" must only exist in "right"
+		# "file" and "file2" must be listed in both "left" and "right"
+		test "1" = $(grep sub output | wc -l) &&
+		test "2" = $(grep file"$" output | wc -l) &&
+		test "2" = $(grep file2 output | wc -l)
+	)
+'
+
+run_dir_diff_test 'difftool --dir-diff v1 from subdirectory' '
+	(
+		cd sub &&
+		git difftool --dir-diff $symlinks --extcmd ls v1 >output &&
+		# "sub" and "file" exist in both v1 and HEAD.
+		# "file2" is unchanged.
+		test "2" = $(grep sub output | wc -l) &&
+		test "2" = $(grep file output | wc -l) &&
+		test "0" = $(grep file2 output | wc -l)
+	)
+'
+
+run_dir_diff_test 'difftool --dir-diff branch from subdirectory w/ pathspec' '
+	(
+		cd sub &&
+		git difftool --dir-diff $symlinks --extcmd ls branch -- .>output &&
+		# "sub" only exists in "right"
+		# "file" and "file2" must not be listed
+		test "1" = $(grep sub output | wc -l) &&
+		test "0" = $(grep file output | wc -l)
+	)
+'
+
+run_dir_diff_test 'difftool --dir-diff v1 from subdirectory w/ pathspec' '
+	(
+		cd sub &&
+		git difftool --dir-diff $symlinks --extcmd ls v1 -- .>output &&
+		# "sub" exists in v1 and HEAD
+		# "file" is filtered out by the pathspec
+		test "2" = $(grep sub output | wc -l) &&
+		test "0" = $(grep file output | wc -l)
 	)
 '
 