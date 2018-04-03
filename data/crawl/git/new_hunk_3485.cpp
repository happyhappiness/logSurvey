   shallow repository when a fetch operation tries to auto-follow
   tags.

 * When send-email comes up with an error message to die with upon
   failure to start an SSL session, it tried to read the error
   string from a wrong place.

 * A call to xread() was used without a loop to cope with short
   read in the codepath to stream large blobs to a pack.

 * On platforms with fgetc() and friends defined as macros, the
   configuration parser did not compile.

 * New versions of MediaWiki introduced a new API for returning
   more than 500 results in response to a query, which would cause
   the MediaWiki remote helper to go into an infinite loop.

 * Subversion's serf access method (the only one available in
   Subversion 1.8) for http and https URLs in skelta mode tells its
   caller to open multiple files at a time, which made "git svn
   fetch" complain that "Temp file with moniker 'svn_delta' already
   in use" instead of fetching.


Also contains a handful of trivial code clean-ups, documentation
updates, updates to the test suite, etc.
