@cindex target, deleting on error
Usually when a command fails, if it has changed the target file at all,
the file is corrupted and cannot be used---or at least it is not
completely updated.  Yet the file's timestamp says that it is now up to
date, so the next time @code{make} runs, it will not try to update that
file.  The situation is just the same as when the command is killed by a
signal; @pxref{Interrupts}.  So generally the right thing to do is to
