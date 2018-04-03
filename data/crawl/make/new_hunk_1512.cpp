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

If you use symbolic links, you should implement a fallback for systems
that don't have symbolic links.
