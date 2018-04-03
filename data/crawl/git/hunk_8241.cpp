 #	This is the filter for rewriting the commit's parent list.
 #	It will receive the parent string on stdin and shall output
 #	the new parent string on stdout. The parent string is in
-#	format accepted by `git-commit-tree`: empty for initial
+#	format accepted by `git commit-tree`: empty for initial
 #	commit, "-p parent" for a normal commit and "-p parent1
 #	-p parent2 -p parent3 ..." for a merge commit.
 #
