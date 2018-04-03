 #	modified:   dir1/modified
 #	modified:   sm (modified content)
 #
+# Submodule changes to be committed:
+#
+# * sm $head...$new_head (1):
+#   > Add bar
+#
 # Untracked files:
 #   (use "git add <file>..." to include in what will be committed)
 #
+#	.gitmodules
 #	dir1/untracked
 #	dir2/modified
 #	dir2/untracked
 #	expect
 #	output
 #	untracked
-no changes added to commit (use "git add" and/or "git commit -a")
 EOF
 
 test_expect_success "--ignore-submodules=untracked doesn't suppress submodules with modified content" '
 	git status --ignore-submodules=untracked > output &&
 	test_cmp expect output
 '
 
+test_expect_success ".git/config ignore=untracked doesn't suppress submodules with modified content" '
+	git config --add submodule.subname.ignore untracked &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 head2=$(cd sm && git commit -q -m "2nd commit" foo && git rev-parse --short=7 --verify HEAD)
 
 cat > expect << EOF
 # On branch master
+# Changes to be committed:
+#   (use "git reset HEAD <file>..." to unstage)
+#
+#	modified:   sm
+#
 # Changed but not updated:
 #   (use "git add <file>..." to update what will be committed)
 #   (use "git checkout -- <file>..." to discard changes in working directory)
 #
 #	modified:   dir1/modified
 #	modified:   sm (new commits)
 #
+# Submodule changes to be committed:
+#
+# * sm $head...$new_head (1):
+#   > Add bar
+#
 # Submodules changed but not updated:
 #
-# * sm $head...$head2 (1):
+# * sm $new_head...$head2 (1):
 #   > 2nd commit
 #
 # Untracked files:
 #   (use "git add <file>..." to include in what will be committed)
 #
+#	.gitmodules
 #	dir1/untracked
 #	dir2/modified
 #	dir2/untracked
 #	expect
 #	output
 #	untracked
-no changes added to commit (use "git add" and/or "git commit -a")
 EOF
 
 test_expect_success "--ignore-submodules=untracked doesn't suppress submodule summary" '
 	git status --ignore-submodules=untracked > output &&
 	test_cmp expect output
 '
 
+test_expect_success ".git/config ignore=untracked doesn't suppress submodule summary" '
+	git config --add submodule.subname.ignore untracked &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
 test_expect_success "--ignore-submodules=dirty doesn't suppress submodule summary" '
 	git status --ignore-submodules=dirty > output &&
 	test_cmp expect output
 '
 
+test_expect_success ".git/config ignore=dirty doesn't suppress submodule summary" '
+	git config --add submodule.subname.ignore dirty &&
+	git config --add submodule.subname.path sm &&
+	git status > output &&
+	test_cmp expect output &&
+	git config --remove-section submodule.subname
+'
+
+
 cat > expect << EOF
 # On branch master
 # Changed but not updated:
