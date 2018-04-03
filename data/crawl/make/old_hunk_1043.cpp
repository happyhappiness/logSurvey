@cindex @code{--keep-going}
On these occasions, you should use the @samp{-k} or
@samp{--keep-going} flag.  This tells @code{make} to continue to
consider the other dependencies of the pending targets, remaking them
if necessary, before it gives up and returns nonzero status.  For
example, after an error in compiling one object file, @samp{make -k}
will continue compiling other object files even though it already
knows that linking them will be impossible.  In addition to continuing
after failed shell commands, @samp{make -k} will continue as much as
possible after discovering that it does not know how to make a target
or dependency file.  This will always cause an error message, but
without @samp{-k}, it is a fatal error (@pxref{Options Summary,
,Summary of Options}).@refill

