   not translated by mistake), and TravisCI is told to run them.
   (merge b8e188f6f5 ab/fix-poison-tests later to maint).

 * "git checkout --recurse-submodules" did not quite work with a
   submodule that itself has submodules.
   (merge 218c883783 sb/checkout-recurse-submodules later to maint).

 * Plug some leaks and updates internal API used to implement the
   split index feature to make it easier to avoid such a leak in the
   future.
   (merge de950c5773 nd/split-index-unshare later to maint).

 * "pack-objects" can stream a slice of an existing packfile out when
   the pack bitmap can tell that the reachable objects are all needed
   in the output, without inspecting individual objects.  This
   strategy however would not work well when "--local" and other
   options are in use, and need to be disabled.
   (merge da5a1f8100 jk/disable-pack-reuse-when-broken later to maint).

 * Fix memory leaks pointed out by Coverity (and people).
   (merge 443a12f37b js/plug-leaks later to maint).

 * "git read-tree -m" (no tree-ish) gave a nonsense suggestion "use
   --empty if you want to clear the index".  With "-m", such a request
   will still fail anyway, as you'd need to name at least one tree-ish
   to be merged.
   (merge b9b10d3681 jc/read-tree-empty-with-m later to maint).

 * Make sure our tests would pass when the sources are checked out
   with "platform native" line ending convention by default on
   Windows.  Some "text" files out tests use and the test scripts
   themselves that are meant to be run with /bin/sh, ought to be
   checked out with eol=LF even on Windows.
   (merge 2779f66505 js/eol-on-ourselves later to maint).

 * Introduce the BUG() macro to improve die("BUG: ...").
   (merge 3d7dd2d3b6 jk/bug-to-abort later to maint).

 * Clarify documentation for include.path and includeIf.<condition>.path
   configuration variables.
   (merge ce933ebd5a jk/doc-config-include later to maint).

 * Git sometimes gives an advice in a rhetorical question that does
   not require an answer, which can confuse new users and non native
   speakers.  Attempt to rephrase them.
   (merge 6963893943 ja/do-not-ask-needless-questions later to maint).

 * A few http:// links that are redirected to https:// in the
   documentation have been updated to https:// links.
   (merge 5e68729fd9 jk/update-links-in-docs later to maint).

 * "git for-each-ref --format=..." with %(HEAD) in the format used to
   resolve the HEAD symref as many times as it had processed refs,
   which was wasteful, and "git branch" shared the same problem.
   (merge 613a0e52ea kn/ref-filter-branch-list later to maint).

 * Regression fix to topic recently merged to 'master'.
   (merge d096d7f1ef pw/rebase-i-regression-fix later to maint).

 * The shell completion script (in contrib/) learned "git stash" has
   a new "push" subcommand.
   (merge 3851e4483f tg/stash-push-fixup later to maint).

 * "git interpret-trailers", when used as GIT_EDITOR for "git commit
   -v", looked for and appended to a trailer block at the very end,
   i.e. at the end of the "diff" output.  The command has been
   corrected to pay attention to the cut-mark line "commit -v" adds to
   the buffer---the real trailer block should appear just before it.
   (merge d76650b8d1 bm/interpret-trailers-cut-line-is-eom later to maint).

 * A test allowed both "git push" and "git receive-pack" on the other
   end write their traces into the same file.  This is OK on platforms
   that allows atomically appending to a file opened with O_APPEND,
   but on other platforms led to a mangled output, causing
   intermittent test failures.  This has been fixed by disabling
   traces from "receive-pack" in the test.
   (merge 71406ed4d6 jk/alternate-ref-optim later to maint).

 * Tag objects, which are not reachable from any ref, that point at
   missing objects were mishandled by "git gc" and friends (they
   should silently be ignored instead)
   (merge a3ba6bf10a jk/ignore-broken-tags-when-ignoring-missing-links later to maint).

 * Other minor doc, test and build updates and code cleanups.
   (merge 515360f9e9 jn/credential-doc-on-clear later to maint).
   (merge 0e6d899fee ab/aix-needs-compat-regex later to maint).
   (merge e294e8959f jc/apply-fix-mismerge later to maint).
   (merge 7f1b225153 bw/submodule-with-bs-path later to maint).
   (merge c8f7c8b704 tb/dedup-crlf-tests later to maint).
   (merge 449456ad47 sg/core-filemode-doc-typofix later to maint).
   (merge ba4dce784e km/log-showsignature-doc later to maint).