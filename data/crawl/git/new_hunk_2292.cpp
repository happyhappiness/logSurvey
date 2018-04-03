   CPU cycles.
   (merge a2d5156 jk/ref-cache-non-repository-optim later to maint).

 * "git worktree" had a broken code that attempted to auto-fix
   possible inconsistency that results from end-users moving a
   worktree to different places without telling Git (the original
   repository needs to maintain backpointers to its worktrees, but
   "mv" run by end-users who are not familiar with that fact will
   obviously not adjust them), which actually made things worse
   when triggered.
   (merge 618244e nd/do-not-move-worktree-manually later to maint).

 * The low-level merge machinery has been taught to use CRLF line
   termination when inserting conflict markers to merged contents that
   are themselves CRLF line-terminated.
   (merge 15980de js/xmerge-marker-eol later to maint).

 * "git push --force-with-lease" has been taught to report if the push
   needed to force (or fast-forwarded).
   (merge b2e93f8 aw/push-force-with-lease-reporting later to maint).

 * The emulated "yes" command used in our test scripts has been
   tweaked not to spend too much time generating unnecessary output
   that is not used, to help those who test on Windows where it would
   not stop until it fills the pipe buffer due to lack of SIGPIPE.
   (merge 6129c93 js/test-lib-windows-emulated-yes later to maint).

 * Other minor clean-ups and documentation updates
   (merge 99487cf ss/user-manual later to maint).
   (merge e914ef0 ew/for-each-ref-doc later to maint).