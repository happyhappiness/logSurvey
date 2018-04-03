
By default, there is no load limit.

@node Errors, Interrupts, Parallel, Commands
@section Errors in Commands
@cindex errors (in commands)
@cindex commands, errors in
@cindex exit status (errors)

After each shell command returns, @code{make} looks at its exit status.
If the command completed successfully, the next command line is executed
in a new shell; after the last command line is finished, the rule is
finished.

If there is an error (the exit status is nonzero), @code{make} gives up on
the current rule, and perhaps on all rules.

Sometimes the failure of a certain command does not indicate a problem.
For example, you may use the @code{mkdir} command to ensure that a
directory exists.  If the directory already exists, @code{mkdir} will
report an error, but you probably want @code{make} to continue regardless.

@cindex @code{-} (in commands)
To ignore errors in a command line, write a @samp{-} at the beginning of
the line's text (after the initial tab).  The @samp{-} is discarded before
the command is passed to the shell for execution.

For example,

