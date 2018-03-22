# include <config.h>
#endif

#include <stddef.h>

#if HAVE_ICONV
# include <iconv.h>

# if ! USE_INCLUDED_LIBINTL && HAVE_LANGINFO_CODESET
#  include <langinfo.h>
# endif

# if HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#include "copysym.h"

/* Store into BUF (of size BUFSIZE) a representation of the copyright
   symbol (C-in-a-circle) that is a valid text string for the current
   locale.  Return BUF if successful, and a pointer to some other
   string otherwise.  */

char const *
copyright_symbol (char *buf, size_t bufsize)
{
#if HAVE_ICONV
  char const *outcharset = getenv ("OUTPUT_CHARSET");

  if (! (outcharset && *outcharset))
    {
#if USE_INCLUDED_LIBINTL
      extern char const *locale_charset (void);
      outcharset = locale_charset ();
#else
# if HAVE_LANGINFO_CODESET
      outcharset = nl_langinfo (CODESET);
# endif
#endif
    }

  if (*outcharset)
    {
      iconv_t conv = iconv_open (outcharset, "UTF-8");

      if (conv != (iconv_t) -1)
	{
	  static char const copyright_utf_8[] = "\302\251";
	  char ICONV_CONST *inptr = (char ICONV_CONST *) &copyright_utf_8;
	  size_t inleft = sizeof copyright_utf_8;
	  char *outptr = buf;
	  size_t chars = iconv (conv, &inptr, &inleft, &outptr, &bufsize);

	  iconv_close (conv);

	  if (chars != (size_t) -1)
	    return buf;
	}
    }
#endif

  /* "(C)" is the best we can do in ASCII.  */
  return "(C)";
}
