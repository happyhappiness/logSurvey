addition to continuing after failed shell commands, @samp{make -k} will
continue as much as possible after discovering that it does not know how
to make a target or dependency file.  This will always cause an error
message, but without @samp{-k}, it is a fatal error (@pxref{Options
Summary, ,Summary of Options}).@refill

The usual behavior of @code{make} assumes that your purpose is to get the
goals up to date; once @code{make} learns that this is impossible, it might
