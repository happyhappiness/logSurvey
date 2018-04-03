track are contained in this release (see the maintenance releases'
notes for details).

 * Serving objects from a shallow repository needs to write a
   new file to hold the temporary shallow boundaries but it was not
   cleaned when we exit due to die() or a signal.
   (merge 7839632 jk/shallow-update-fix later to maint).

 * When "git stash pop" stops after failing to apply the stash
   (e.g. due to conflicting changes), the stash is not dropped. State
   that explicitly in the output to let the users know.
   (merge 2d4c993 jc/stash-pop-not-popped later to maint).

 * The labels in "git status" output that describe the nature of
   conflicts (e.g. "both deleted") were limited to 20 bytes, which was
   too short for some l10n (e.g. fr).
   (merge c7cb333 jn/wt-status later to maint).

 * "git clean -d pathspec" did not use the given pathspec correctly
   and ended up cleaning too much.
   (merge 1f2e108 jk/clean-d-pathspec later to maint).