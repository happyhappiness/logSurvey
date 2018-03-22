# include <config.h>
#endif

#include "unicodeio.h"
#include "print-copyr.h"

#include <stdio.h>

#define COPYRIGHT_SIGN 0x00A9

/* Print "(C)".  */

static int
print_parenthesized_c (unsigned int code, void *callback_arg)
{
  FILE *stream = callback_arg;
  return fputs ("(C)", stream);
}

/* Print "Copyright (C) " followed by NOTICE and then a newline,
   transliterating "(C)" to an actual copyright sign (C-in-a-circle)
   if possible.  */

void
print_copyright (char const *notice)
{
  fputs ("Copyright ", stdout);
  unicode_to_mb (COPYRIGHT_SIGN, print_unicode_success, print_parenthesized_c,
		 stdout);
  fputc (' ', stdout);
  puts (notice);
}
