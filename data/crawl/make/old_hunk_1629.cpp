If there is an error (the exit status is nonzero), @code{make} gives up on
the current rule, and perhaps on all rules.

Sometimes it does not matter whether a command fails.  For example, you
may use the @code{mkdir} command to insure that a directory exists.  If
the directory already exists, @code{mkdir} will report an error, but you
probably want @code{make} to continue regardless.

@cindex - (in commands)
To ignore errors in a command line, write a @samp{-} at the beginning of
the line's text (after the initial tab).  The @samp{-} is discarded before
the command is passed to the shell for execution.

@cindex -i
@findex .IGNORE
When @code{make} is run with the @samp{-i} flag, errors are ignored in
all commands of all rules.  A rule in the makefile for the special target
@code{.IGNORE} has the same effect.  These ways of ignoring errors are
obsolete because @samp{-} is more general.

When errors are to be ignored, because of either a @samp{-} or the
@samp{-i} flag, @code{make} treats an error return just like success,
except that it prints out a message telling you the status code the
command exited with and saying that the error has been ignored.

@cindex -k
When an error happens that @code{make} has not been told to ignore,
it implies that the current target cannot be correctly remade, and neither
can any other that depends on it either directly or indirectly.  No further
