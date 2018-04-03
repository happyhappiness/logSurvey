there is no limit on the number of job slots.  The default number of job
slots is one, which means serial execution (one thing at a time).

Handling recursive @code{make} invocations raises issues for parallel
execution.  For more information on this, see @ref{Options/Recursion,
,Communicating Options to a Sub-@code{make}}.

If a recipe fails (is killed by a signal or exits with a nonzero
status), and errors are not ignored for that recipe (@pxref{Errors,
,Errors in Recipes}), the remaining recipe lines to remake the same
target will not be run.  If a recipe fails and the @samp{-k} or
@samp{--keep-going} option was not given (@pxref{Options Summary,
,Summary of Options}), @code{make} aborts execution.  If make
terminates for any reason (including a signal) with child processes
running, it waits for them to finish before actually exiting.@refill

