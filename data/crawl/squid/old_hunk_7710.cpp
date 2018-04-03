EOF


XTRA_OBJS=''
if test "$HAVE_LIBMALLOC" = "yes" ; then
	if test -r /usr/lib/debug/malloc.o ; then
