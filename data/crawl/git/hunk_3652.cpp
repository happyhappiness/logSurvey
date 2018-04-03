 	)
 '
 
+run_dir_diff_test 'difftool --dir-diff when worktree file is missing' '
+	test_when_finished git reset --hard &&
+	rm file2 &&
+	git difftool --dir-diff $symlinks --extcmd ls branch master >output &&
+	grep file2 output
+'
+
 write_script .git/CHECK_SYMLINKS <<\EOF
 for f in file file2 sub/sub
 do