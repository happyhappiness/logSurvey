there is no limit on the number of job slots.  The default number of job
slots is one, which means serial execution (one thing at a time).

When running several recipes simultaneously the output from each
recipe appears as soon as it is generated, with the result that
messages from different recipes may be interspersed.  To avoid this
you can use the @samp{--output-sync} (@samp{-O}) option; if this
option is provided then the output from each recipe will be saved
until the recipe is complete, then written all at once.  This ensures
that output from different recipes is not mixed together.

Another problem is that two processes cannot both take input from the
same device; so to make sure that only one recipe tries to take input
from the terminal at once, @code{make} will invalidate the standard
input streams of all but one running recipe.  This means that
attempting to read from standard input will usually be a fatal error (a
@samp{Broken pipe} signal) for most child processes if there are
several.
@cindex broken pipe
@cindex standard input

It is unpredictable which recipe will have a valid standard input stream
(which will come from the terminal, or wherever you redirect the standard
input of @code{make}).  The first recipe run will always get it first, and
the first recipe started after that one finishes will get it next, and so
on.

We will change how this aspect of @code{make} works if we find a better
alternative.  In the mean time, you should not rely on any recipe using
standard input at all if you are using the parallel execution feature; but
if you are not using this feature, then standard input works normally in
all recipes.

Finally, handling recursive @code{make} invocations raises issues.  For
more information on this, see
@ref{Options/Recursion, ,Communicating Options to a Sub-@code{make}}.

If a recipe fails (is killed by a signal or exits with a nonzero
status), and errors are not ignored for that recipe
(@pxref{Errors, ,Errors in Recipes}),
the remaining recipe lines to remake the same target will not be run.
If a recipe fails and the @samp{-k} or @samp{--keep-going}
option was not given
(@pxref{Options Summary, ,Summary of Options}),
@code{make} aborts execution.  If make
terminates for any reason (including a signal) with child processes
running, it waits for them to finish before actually exiting.@refill

