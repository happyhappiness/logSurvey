
By default, there is no load limit.

@node Errors, Interrupts, Parallel, Recipes
@section Errors in Recipes
@cindex errors (in recipes)
@cindex recipes, errors in
@cindex exit status (errors)

After each shell invocation returns, @code{make} looks at its exit
status.  If the shell completed successfully (the exit status is
zero), the next line in the recipe is executed in a new shell; after
the last line is finished, the rule is finished.

If there is an error (the exit status is nonzero), @code{make} gives up on
the current rule, and perhaps on all rules.

Sometimes the failure of a certain recipe line does not indicate a problem.
For example, you may use the @code{mkdir} command to ensure that a
directory exists.  If the directory already exists, @code{mkdir} will
report an error, but you probably want @code{make} to continue regardless.

@cindex @code{-} (in recipes)
To ignore errors in a recipe line, write a @samp{-} at the beginning
of the line's text (after the initial tab).  The @samp{-} is discarded
before the line is passed to the shell for execution.

For example,

