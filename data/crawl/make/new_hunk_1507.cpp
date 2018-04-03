default.
@cindex Emacs (@code{M-x compile})

@findex .DELETE_ON_ERROR
@cindex deletion of target files
@cindex removal of target files
@cindex target, deleting on error
Usually when a command fails, if it has changed the target file at all,
the file is corrupted and cannot be used---or at least it is not
completely updated.  Yet the file's timestamp says that it is now up to
date, so the next time @code{make} runs, it will not try to update that
file.  The situation is just the same as when the command is killed by a
signal; @pxref{Interrupts}.  So generally the right thing to do is to
delete the target file if the command fails after beginning to change
the file.  @code{make} will do this if @code{.DELETE_ON_ERROR} appears
as a target.  This is almost always what you want @code{make} to do, but
it is not historical practice; so for compatibility, you must explicitly
request it.

@node Interrupts, Recursion, Errors, Commands
@section Interrupting or Killing @code{make}
@cindex interrupt
@cindex signal
@cindex deletion of target files
@cindex removal of target files
@cindex target, deleting on interrupt
@cindex killing (interruption)
