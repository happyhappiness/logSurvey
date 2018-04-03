   release (yet).

 * The historical argument order "git merge <msg> HEAD <commit>..."
   has been deprecated for quite some time, and is now removed.

 * The default location "~/.git-credential-cache/socket" for the
   socket used to communicate with the credential-cache daemon has
   been moved to "~/.cache/git/credential/socket".

 * Git now avoids blindly falling back to ".git" when the setup
   sequence said we are _not_ in Git repository.  A corner case that
   happens to work right now may be broken by a call to die("BUG").
   We've tried hard to locate such cases and fixed them, but there
   might still be cases that need to be addressed--bug reports are
   greatly appreciated.


Updates since v2.12
-------------------
