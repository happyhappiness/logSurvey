mean:

@example
ar bison cc flex install ld lex
make makeinfo ranlib texi2dvi yacc
@end example

Use the following @code{make} variables:

@example
$(AR) $(BISON) $(CC) $(FLEX) $(INSTALL) $(LD) $(LEX)
$(MAKE) $(MAKEINFO) $(RANLIB) $(TEXI2DVI) $(YACC)
@end example

When you use @code{ranlib}, you should make sure nothing bad happens if
the system does not have @code{ranlib}.  Arrange to ignore an error
from that command, and print a message before the command to tell the
user that failure of the @code{ranlib} command does not mean a problem.
(The Autoconf @samp{AC_PROG_RANLIB} macro can help with this.)

If you use symbolic links, you should implement a fallback for systems
that don't have symbolic links.

It is ok to use other utilities in Makefile portions (or scripts)
intended only for particular systems where you know those utilities
exist.
