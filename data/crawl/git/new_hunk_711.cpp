 * Fix for NO_PTHREADS option.
   (merge 2225e1ea20 bw/grep-recurse-submodules later to maint).

 * Git now avoids blindly falling back to ".git" when the setup
   sequence said we are _not_ in Git repository.  A corner case that
   happens to work right now may be broken by a call to die("BUG").
   (merge b1ef400eec jk/no-looking-at-dotgit-outside-repo-final later to maint).

 * A few commands that recently learned the "--recurse-submodule"
   option misbehaved when started from a subdirectory of the
   superproject.
   (merge b2dfeb7c00 bw/recurse-submodules-relative-fix later to maint).

 * FreeBSD implementation of getcwd(3) behaved differently when an
   intermediate directory is unreadable/unsearchable depending on the
   length of the buffer provided, which our strbuf_getcwd() was not
   aware of.  strbuf_getcwd() has been taught to cope with it better.
   (merge a54e938e5b rs/freebsd-getcwd-workaround later to maint).

 * A recent update to "rebase -i" stopped running hooks for the "git
   commit" command during "reword" action, which has been fixed.

 * Removing an entry from a notes tree and then looking another note
   entry from the resulting tree using the internal notes API
   functions did not work as expected.  No in-tree users of the API
   has such access pattern, but it still is worth fixing.

 * "git receive-pack" could have been forced to die by attempting
   allocate an unreasonably large amount of memory with a crafted push
   certificate; this has been fixed.
   (merge f2214dede9 bc/push-cert-receive-fix later to maint).

 * Other minor doc, test and build updates and code cleanups.
   (merge df2a6e38b7 jk/pager-in-use later to maint).
   (merge 75ec4a6cb0 ab/branch-list-doc later to maint).
   (merge 3e5b36c637 sg/skip-prefix-in-prettify-refname later to maint).
   (merge 2c5e2865cc jk/fast-import-cleanup later to maint).
   (merge 4473060bc2 ab/test-readme-updates later to maint).
   (merge 48a96972fd ab/doc-submitting later to maint).
   (merge f5c2bc2b96 jk/make-coccicheck-detect-errors later to maint).