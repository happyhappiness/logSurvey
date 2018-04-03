 * Leakage of lockfiles in the config subsystem has been fixed.
   (merge c06fa62dfc nd/config-misc-fixes later to maint).

 * It is natural that "git gc --auto" may not attempt to pack
   everything into a single pack, and there is no point in warning
   when the user has configured the system to use the pack bitmap,
   leading to disabling further "gc".
   (merge 1c409a705c dt/disable-bitmap-in-auto-gc later to maint).

 * "git archive" did not read the standard configuration files, and
   failed to notice a file that is marked as binary via the userdiff
   driver configuration.
   (merge 965cba2e7e jk/archive-zip-userdiff-config later to maint).

 * "git blame --porcelain" misidentified the "previous" <commit, path>
   pair (aka "source") when contents came from two or more files.
   (merge 4e76832984 jk/blame-fixes later to maint).

 * "git rebase -i" with a recent update started showing an incorrect
   count when squashing more than 10 commits.
   (merge 356b8ecff1 jk/rebase-i-squash-count-fix later to maint).

 * "git <cmd> @{push}" on a detached HEAD used to segfault; it has
   been corrected to error out with a message.
   (merge b10731f43d km/branch-get-push-while-detached later to maint).

 * Running "git add a/b" when "a" is a submodule correctly errored
   out, but without a meaningful error message.
   (merge 2d81c48fa7 sb/pathspec-errors later to maint).

 * Typing ^C to pager, which usually does not kill it, killed Git and
   took the pager down as a collateral damage in certain process-tree
   structure.  This has been fixed.
   (merge 46df6906f3 jk/execv-dashed-external later to maint).

 * "git mergetool" without any pathspec on the command line that is
   run from a subdirectory became no-op in Git v2.11 by mistake, which
   has been fixed.

 * Retire long unused/unmaintained gitview from the contrib/ area.
   (merge 3120925c25 sb/remove-gitview later to maint).

 * Other minor doc, test and build updates and code cleanups.
   (merge f2627d9b19 sb/submodule-config-cleanup later to maint).
   (merge 384f1a167b sb/unpack-trees-cleanup later to maint).