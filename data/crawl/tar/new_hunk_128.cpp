  while (i);
}


static bool
to_chars (int negative, uintmax_t value, size_t valsize,
	  uintmax_t (*substitute) (int *),
	  char *where, size_t size, const char *type);

static bool
to_chars_subst (int negative, int gnu_format, uintmax_t value, size_t valsize,
		uintmax_t (*substitute) (int *),
		char *where, size_t size, const char *type)
{
  uintmax_t maxval = (gnu_format
		      ? MAX_VAL_WITH_DIGITS (size - 1, LG_256)
		      : MAX_VAL_WITH_DIGITS (size - 1, LG_8));
  char valbuf[UINTMAX_STRSIZE_BOUND + 1];
  char maxbuf[UINTMAX_STRSIZE_BOUND];
  char minbuf[UINTMAX_STRSIZE_BOUND + 1];
  char const *minval_string;
  char const *maxval_string = STRINGIFY_BIGINT (maxval, maxbuf);
  char const *value_string;
  char *p;
    
  if (gnu_format)
    {
      uintmax_t m = maxval + 1 ? maxval + 1 : maxval / 2 + 1;
      char *p = STRINGIFY_BIGINT (m, minbuf + 1);
      *--p = '-';
      minval_string = p;
    }
  else
    minval_string = "0";
  
  if (negative)
    {
      char *p = STRINGIFY_BIGINT (- value, valbuf + 1);
      *--p = '-';
      value_string = p;
    }
  else
    value_string = STRINGIFY_BIGINT (value, valbuf);
	  
  if (substitute)
    {
      int negsub;
      uintmax_t sub = substitute (&negsub) & maxval;
      /* FIXME: This is the only place where GNU_FORMAT differs from
	 OLDGNU_FORMAT. Apart from this they are completely identical. */
      uintmax_t s = (negsub &= archive_format == GNU_FORMAT) ? - sub : sub;
      char subbuf[UINTMAX_STRSIZE_BOUND + 1];
      char *sub_string = STRINGIFY_BIGINT (s, subbuf + 1);
      if (negsub)
	*--sub_string = '-';
      WARN ((0, 0, _("value %s out of %s range %s..%s; substituting %s"),
	     value_string, type, minval_string, maxval_string,
	     sub_string));
      to_chars (negsub, s, valsize, 0, where, size, type);
    }
  else
    ERROR ((0, 0, _("value %s out of %s range %s..%s"),
	    value_string, type, minval_string, maxval_string));
}

/* Convert NEGATIVE VALUE (which was originally of size VALSIZE) to
   external form, using SUBSTITUTE (...) if VALUE won't fit.  Output
   to buffer WHERE with size SIZE.  NEGATIVE is 1 iff VALUE was
