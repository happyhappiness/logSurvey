@code{gmk_expand} and then again by the @code{eval} function.  Using
@code{gmk_eval} the buffer is only expanded once, at most (as it's
read by the @code{make} parser).

@subsubheading Memory Management

Some systems allow for different memory management schemes.  Thus you
should never pass memory that you've allocated directly to any
@code{make} function, nor should you attempt to directly free any
memory returned to you by any @code{make} function.  Instead, use the
@code{gmk_alloc} and @code{gmk_free} functions.

@table @code
@item gmk_alloc
@findex gmk_alloc
Return a pointer to a newly-allocated buffer.  This function will
always return a valid pointer; if not enough memory is available
@code{make} will exit.

@item gmk_free
@findex gmk_free
Free a buffer returned to you by @code{make}.  Once the
@code{gmk_free} function returns the string will no longer be valid.
@end table

@node Loaded Object Example,  , Loaded Object API, Loading Objects
@subsection Example Loaded Object
@cindex loaded object example
@cindex example of loaded objects

Let's suppose we wanted to write a new GNU @code{make} function that
would create a temporary file and return its name.  We would like our
function to take a prefix as an argument.  First we can write the
function in a file @file{mk_temp.c}:

@example
@group
#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <gnumake.h>

char *
gen_tmpfile(const char *nm, int argc, char **argv)
@{
  int fd;

  /* Compute the size of the filename and allocate space for it.  */
  int len = strlen (argv[0]) + 6 + 1;
  char *buf = gmk_alloc (len);

  strcpy (buf, argv[0]);
  strcat (buf, "XXXXXX");

  fd = mkstemp(buf);
  if (fd >= 0)
    @{
      /* Don't leak the file descriptor.  */
      close (fd);
      return buf;
    @}

  /* Failure.  */
  fprintf (stderr, "mkstemp(%s) failed: %s\n", buf, strerror (errno));
  gmk_free (buf);
  return NULL;
@}

int
mk_temp_gmk_setup ()
@{
  /* Register the function with make name "mk-temp".  */
  gmk_add_function ("mk-temp", gen_tmpfile, 1, 1, 1);
  return 1;
@}
@end group
@end example

Next, we will write a makefile that can build this shared object, load
it, and use it:

@example
@group
all:
        @@echo Temporary file: $(mk-temp tmpfile.)

load mk_temp.so

mk_temp.so: mk_temp.c
        $(CC) -shared -fPIC -o $@ $<
@end group
@end example

Now when you run @code{make} you'll see something like:

@example
$ make
cc -shared -fPIC -o mk_temp.so mk_temp.c
Temporary filename: tmpfile.A7JEwd
@end example

@node Features, Missing, Extending make, Top
@chapter Features of GNU @code{make}
@cindex features of GNU @code{make}
