   recurses into, but this was incorrect when the command was not run
   from the root level of the superproject.

 * The test scripts for "git p4" (but not "git p4" implementation
   itself) has been updated so that they would work even on a system
   where the installed version of Python is python 3.

 * The "user.useConfigOnly" configuration variable makes it an error
   if users do not explicitly set user.name and user.email.  However,
   its check was not done early enough and allowed another error to
   trigger, reporting that the default value we guessed from the
   system setting was unusable.  This was a suboptimal end-user
   experience as we want the users to set user.name/user.email without
   relying on the auto-detection at all.

 * "git mv old new" did not adjust the path for a submodule that lives
   as a subdirectory inside old/ directory correctly.

 * "git push" from a corrupt repository that attempts to push a large
   number of refs deadlocked; the thread to relay rejection notices
   for these ref updates blocked on writing them to the main thread,
   after the main thread at the receiving end notices that the push
   failed and decides not to read these notices and return a failure.

 * A question by "git send-email" to ask the identity of the sender
   has been updated.

 * Recent update to Git LFS broke "git p4" by changing the output from
   its "lfs pointer" subcommand.

 * Some multi-byte encoding can have a backslash byte as a later part
   of one letter, which would confuse "highlight" filter used in
   gitweb.

Also contains minor documentation updates and code clean-ups.
