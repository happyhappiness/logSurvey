@end group
@end example

A phony target should not be a prerequisite of a real target file; if it
is, its commands are run every time @code{make} goes to update that
file.  As long as a phony target is never a prerequisite of a real
