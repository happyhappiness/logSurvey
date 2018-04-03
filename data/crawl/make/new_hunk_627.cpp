@end group
@end example

There are problems with this method, however.  First, any error
detected in a submake is ignored by this rule, so it will continue
to build the rest of the directories even when one fails.  This can be
overcome by adding shell commands to note the error and exit, but then
it will do so even if @code{make} is invoked with the @code{-k}
option, which is unfortunate.  Second, and perhaps more importantly,
you cannot take advantage of @code{make}'s ability to build targets in
parallel (@pxref{Parallel, ,Parallel Execution}), since there is only
one rule.

By declaring the subdirectories as phony targets (you must do this as
the subdirectory obviously always exists; otherwise it won't be built)
