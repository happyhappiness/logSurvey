   the GIT_DIR discovery logic to escape the ceiling.
   (merge 059b379 mh/ceiling later to maint).

 * When attempting to read the XDG-style $HOME/.config/git/config and
   finding that $HOME/.config/git is a file, we gave a wrong error
   message, instead of treating the case as "a custom config file does
   not exist there" and moving on.
   (merge 8f2bbe4 jn/warn-on-inaccessible-loosen later to maint).

 * The behaviour visible to the end users was confusing, when they
   attempt to kill a process spawned in the editor that was in turn
