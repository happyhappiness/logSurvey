track are contained in this release (see the maintenance releases' notes
for details).

 * The "--[no-]informative-errors" options to "git daemon" were parsed
   a bit too loosely, allowing any other string after these option
   names.
   (merge 82246b7 nd/daemon-informative-errors-typofix later to maint).

 * There is no reason to have a hardcoded upper limit of the number of
   parents for an octopus merge, created via the graft mechanism, but
   there was.
   (merge e228c17 js/lift-parent-count-limit later to maint).

 * The basic test used to leave unnecessary trash directories in the
   t/ directory.
   (merge 738a8be jk/test-framework-updates later to maint).

 * "git merge-base --octopus" used to leave cleaning up suboptimal
   result to the caller, but now it does the clean-up itself.
   (merge 8f29299 bm/merge-base-octopus-dedup later to maint).

 * A "gc" process running as a different user should be able to stop a
   new "gc" process from starting, but it didn't.
   (merge ed7eda8 km/gc-eperm later to maint).

 * An earlier "clean-up" introduced an unnecessary memory leak.
   (merge e1c1a32 jk/credential-plug-leak later to maint).

 * "git add -A" (no other arguments) in a totally empty working tree
   used to emit an error.
   (merge 64ed07c nd/add-empty-fix later to maint).

 * "git log --decorate" did not handle a tag pointed by another tag
   nicely.
   (merge 5e1361c bc/log-decoration later to maint).

 * When we figure out how many file descriptors to allocate for
   keeping packfiles open, a system with non-working getrlimit() could
   cause us to die(), but because we make this call only to get a
   rough estimate of how many is available and we do not even attempt
   to use up all file descriptors available ourselves, it is nicer to
   fall back to a reasonable low value rather than dying.
   (merge 491a8de jh/rlimit-nofile-fallback later to maint).

 * read_sha1_file(), that is the workhorse to read the contents given
   an object name, honoured object replacements, but there was no
   corresponding mechanism to sha1_object_info() that was used to
   obtain the metainfo (e.g. type & size) about the object.  This led
   callers to weird inconsistencies.
   (merge 663a856 cc/replace-object-info later to maint).

 * "git cat-file --batch=", an admittedly useless command, did not
   behave very well.
   (merge 6554dfa jk/cat-file-regression-fix later to maint).

 * "git rev-parse <revs> -- <paths>" did not implement the usual
   disambiguation rules the commands in the "git log" family used in
   the same way.
   (merge 62f162f jk/rev-parse-double-dashes later to maint).

 * "git mv A B/", when B does not exist as a directory, should error
   out, but it didn't.
   (merge c57f628 mm/mv-file-to-no-such-dir-with-slash later to maint).