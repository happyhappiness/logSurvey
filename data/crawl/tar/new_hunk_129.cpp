   SUBSTITUTE the address of an 0-or-1 flag recording whether the
   substitute value is negative.  */

static bool
to_chars (int negative, uintmax_t value, size_t valsize,
	  uintmax_t (*substitute) (int *),
	  char *where, size_t size, const char *type)
{
  int gnu_format = (archive_format == GNU_FORMAT
		    || archive_format == OLDGNU_FORMAT);

  /* Generate the POSIX octal representation if the number fits.  */
  if (! negative && value <= MAX_VAL_WITH_DIGITS (size - 1, LG_8))
    {
      where[size - 1] = '\0';
      to_octal (value, where, size - 1);
      return true;
    }
  else if (gnu_format)
    {
      /* Try to cope with the number by using traditional GNU format
	 methods */

      /* Generate the base-256 representation if the number fits.  */
      if (((negative ? -1 - value : value)
	   <= MAX_VAL_WITH_DIGITS (size - 1, LG_256)))
	{
	  where[0] = negative ? -1 : 1 << (LG_256 - 1);
	  to_base256 (negative, value, where + 1, size - 1);
	  return true;
	}

      /* Otherwise, if the number is negative, and if it would not cause
	 ambiguity on this host by confusing positive with negative
	 values, then generate the POSIX octal representation of the value
	 modulo 2**(field bits).  The resulting tar file is
	 machine-dependent, since it depends on the host word size.  Yuck!
	 But this is the traditional behavior.  */
      else if (negative && valsize * CHAR_BIT <= (size - 1) * LG_8)
	{
	  static int warned_once;
	  if (! warned_once)
	    {
	      warned_once = 1;
	      WARN ((0, 0, _("Generating negative octal headers")));
	    }
	  where[size - 1] = '\0';
	  to_octal (value & MAX_VAL_WITH_DIGITS (valsize * CHAR_BIT, 1),
		    where, size - 1);
	  return true;
	}
      /* Otherwise fall back to substitution, if possible: */
    }
  else
    substitute = NULL; /* No substitution for formats, other than GNU */
  
  return to_chars_subst (negative, gnu_format, value, valsize, substitute,
			 where, size, type);
}

static uintmax_t
