 	(exit $status)
 '
 
+(cd sm && echo > bar && git add bar && git commit -q -m 'Add bar' && cd .. && git add sm)
+new_head=$(cd sm && git rev-parse --short=7 --verify HEAD)
+touch .gitmodules
+
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
 
 test_expect_success '--ignore-submodules=untracked suppresses submodules with untracked content' '
