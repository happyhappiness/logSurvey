 * Help those who debug http(s) part of the system.
   (merge 0054045 sp/remote-curl-ssl-strerror later to maint).

 * The internal API to interact with "remote.*" configuration
   variables has been streamlined.

 * The ref-filter's format-parsing code has been refactored, in
   preparation for "branch --format" and friends.

 * Traditionally, the tests that try commands that work on the
   contents in the working tree were named with "worktree" in their
   filenames, but with the recent addition of "git worktree"
   subcommand, whose tests are also named similarly, it has become
   harder to tell them apart.  The traditional tests have been renamed
   to use "work-tree" instead in an attempt to differentiate them.
   (merge 5549029 mg/work-tree-tests later to maint).

 * Many codepaths forget to check return value from git_config_set();
   the function is made to die() to make sure we do not proceed when
   setting a configuration variable failed.
   (merge 3d18064 ps/config-error later to maint).

 * Handling of errors while writing into our internal asynchronous
   process has been made more robust, which reduces flakiness in our
   tests.
   (merge 43f3afc jk/epipe-in-async later to maint).

 * There is a new DEVELOPER knob that enables many compiler warning
   options in the Makefile.


Also contains various documentation updates and code clean-ups.


