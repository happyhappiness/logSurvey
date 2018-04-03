mean:

@example
ar bison cc flex install ld lex make ranlib yacc
@end example

When you use @code{ranlib}, you should test whether it exists, and run
it only if it exists, so that the distribution will work on systems that
don't have @code{ranlib}.

If you use symbolic links, you should implement a fallback for systems
that don't have symbolic links.
