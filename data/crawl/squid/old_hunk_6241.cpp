fi
rm -f conftest*

XTRA_OBJS=''
if test "$ac_cv_lib_malloc_main" = "yes" ; then
	if test -r /usr/lib/debug/malloc.o ; then
