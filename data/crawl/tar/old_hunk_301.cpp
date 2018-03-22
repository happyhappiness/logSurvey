      /* Get back to the initial shift state.  */
      res = iconv (utf8_to_local, NULL, NULL, &outptr, &outbytesleft);
      if (res == (size_t)(-1))
	error (1, errno, _("cannot convert U+%04X to local character set"),
	       code);
# endif

      callback (outbuf, outptr - outbuf, callback_arg);
#else
      error (1, 0,
	     _("cannot convert U+%04X to local character set: iconv function not available"),
	     code);
#endif
    }
}

/* Simple callback that outputs the converted string.
   The STREAM is passed as callback_arg.  */
static void
fprintf_callback (const char *buf, size_t buflen, void *callback_arg)
{
  FILE *stream = (FILE *) callback_arg;

  fwrite (buf, 1, buflen, stream);
}

/* Outputs the Unicode character CODE to the output stream STREAM.
   Assumes that the locale doesn't change between two calls.  */
void
print_unicode_char (FILE *stream, unsigned int code)
{
  unicode_to_mb (code, fprintf_callback, stream);
}
