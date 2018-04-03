 * "git mergetool" learned to honor "-O<orderfile>" to control the
   order of paths to present to the end user.

 * "git diff/log --ws-error-highlight=<kind>" lacked the corresponding
   configuration variable to set it by default.

 * "git ls-files" learned "--recurse-submodules" option that can be
   used to get a listing of tracked files across submodules (i.e. this
   only works with "--cached" option, not for listing untracked or
   ignored files).  This would be a useful tool to sit on the upstream
   side of a pipe that is read with xargs to work on all working tree
   files from the top-level superproject.

 * A new credential helper that talks via "libsecret" with
   implementations of XDG Secret Service API has been added to
   contrib/credential/.

 * The GPG verification status shown in "%G?" pretty format specifier
   was not rich enough to differentiate a signature made by an expired
   key, a signature made by a revoked key, etc.  New output letters
   have been assigned to express them.

 * In addition to purely abbreviated commit object names, "gitweb"
   learned to turn "git describe" output (e.g. v2.9.3-599-g2376d31787)
   into clickable links in its output.


Performance, Internal Implementation, Development Support etc.

