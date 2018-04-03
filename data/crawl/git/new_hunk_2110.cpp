   from the root level of the superproject.
   (merge 2ab5660 sb/submodule-path-misc-bugs later to maint).

 * The "user.useConfigOnly" configuration variable makes it an error
   if users do not explicitly set user.name and user.email.  However,
   its check was not done early enough and allowed another error to
   trigger, reporting that the default value we guessed from the
   system setting was unusable.  This was a suboptimal end-user
   experience as we want the users to set user.name/user.email without
   relying on the auto-detection at all.
   (merge d3c06c1 da/user-useconfigonly later to maint).

 * "git mv old new" did not adjust the path for a submodule that lives
   as a subdirectory inside old/ directory correctly.
   (merge a127331 sb/mv-submodule-fix later to maint).

 * "git replace -e" did not honour "core.editor" configuration.
   (merge 36b1437 js/replace-edit-use-editor-configuration later to maint).

 * "git push" from a corrupt repository that attempts to push a large
   number of refs deadlocked; the thread to relay rejection notices
   for these ref updates blocked on writing them to the main thread,
   after the main thread at the receiving end notices that the push
   failed and decides not to read these notices and return a failure.
   (merge c4b2751 jk/push-client-deadlock-fix later to maint).

 * mmap emulation on Windows has been optimized and work better without
   consuming paging store when not needed.
   (merge d5425d1 js/win32-mmap later to maint).

 * Other minor clean-ups and documentation updates
   (merge aed7480 mm/lockfile-error-message later to maint).
   (merge bfee614 jc/index-pack later to maint).