    mergetool" has been modernized to match recent versions of xxdiff.
    (merge 6cf5f6cef7 da/mergetool-xxdiff-hotkey later to maint).
 
+ * Unlike "git am --abort", "git cherry-pick --abort" moved HEAD back
+   to where cherry-pick started while picking multiple changes, when
+   the cherry-pick stopped to ask for help from the user, and the user
+   did "git reset --hard" to a different commit in order to re-attempt
+   the operation.
+   (merge ce73bb22d8 sb/sequencer-abort-safety later to maint).
+
+ * Code cleanup in shallow boundary computation.
+   (merge 649b0c316a nd/shallow-fixup later to maint).
+
+ * A recent update to receive-pack to make it easier to drop garbage
+   objects made it clear that GIT_ALTERNATE_OBJECT_DIRECTORIES cannot
+   have a pathname with a colon in it (no surprise!), and this in turn
+   made it impossible to push into a repository at such a path.  This
+   has been fixed by introducing a quoting mechanism used when
+   appending such a path to the colon-separated list.
+   (merge 5e74824fac jk/quote-env-path-list-component later to maint).
+
+ * The function usage_msg_opt() has been updated to say "fatal:"
+   before the custom message programs give, when they want to die
+   with a message about wrong command line options followed by the
+   standard usage string.
+   (merge 87433261a4 jk/parseopt-usage-msg-opt later to maint).
+
+ * "git index-pack --stdin" needs an access to an existing repository,
+   but "git index-pack file.pack" to generate an .idx file that
+   corresponds to a packfile does not.
+   (merge 29401e1575 jk/index-pack-wo-repo-from-stdin later to maint).
+
+ * Fix for NDEBUG builds.
+   (merge 08414938a2 jt/mailinfo-fold-in-body-headers later to maint).
+
  * Other minor doc, test and build updates and code cleanups.
    (merge fa6ca11105 nd/qsort-in-merge-recursive later to maint).
    (merge fa3142c919 ak/lazy-prereq-mktemp later to maint).