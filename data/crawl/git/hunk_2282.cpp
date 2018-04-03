+Git v2.7.2 Release Notes
+========================
+
+Fixes since v2.7.1
+------------------
+
+ * The low-level merge machinery has been taught to use CRLF line
+   termination when inserting conflict markers to merged contents that
+   are themselves CRLF line-terminated.
+
+ * "git worktree" had a broken code that attempted to auto-fix
+   possible inconsistency that results from end-users moving a
+   worktree to different places without telling Git (the original
+   repository needs to maintain backpointers to its worktrees, but
+   "mv" run by end-users who are not familiar with that fact will
+   obviously not adjust them), which actually made things worse
+   when triggered.
+
+ * "git push --force-with-lease" has been taught to report if the push
+   needed to force (or fast-forwarded).
+
+ * The emulated "yes" command used in our test scripts has been
+   tweaked not to spend too much time generating unnecessary output
+   that is not used, to help those who test on Windows where it would
+   not stop until it fills the pipe buffer due to lack of SIGPIPE.
+
+Also includes tiny documentation and test updates.
-Documentation/RelNotes/2.7.1.txt
+Documentation/RelNotes/2.7.2.txt
