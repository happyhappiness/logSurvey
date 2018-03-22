  xheader_print (xhdr, keyword, code_timespec (t, buf));
}

enum decode_time_status
  {
    decode_time_success,
    decode_time_range,
    decode_time_bad_header
  };

static enum decode_time_status
_decode_time (struct timespec *ts, char const *arg, char const *keyword)
{
  time_t s;
  unsigned long int ns = 0;
  char *p;
  char *arg_lim;
  bool negative = *arg == '-';

  errno = 0;

  if (ISDIGIT (arg[negative]))
    {
      if (negative)
	{
	  intmax_t i = strtoimax (arg, &arg_lim, 10);
	  if (TYPE_SIGNED (time_t) ? i < TYPE_MINIMUM (time_t) : i < 0)
	    return decode_time_range;
	  s = i;
	}
      else
	{
	  uintmax_t i = strtoumax (arg, &arg_lim, 10);
	  if (TYPE_MAXIMUM (time_t) < i)
	    return decode_time_range;
	  s = i;
	}

      p = arg_lim;

      if (errno == ERANGE)
	return decode_time_range;

      if (*p == '.')
	{
	  int digits = 0;
	  bool trailing_nonzero = false;

	  while (ISDIGIT (*++p))
	    if (digits < LOG10_BILLION)
	      {
		ns = 10 * ns + (*p - '0');
		digits++;
	      }
	    else
	      trailing_nonzero |= *p != '0';

	  while (digits++ < LOG10_BILLION)
	    ns *= 10;

	  if (negative)
	    {
	      /* Convert "-1.10000000000001" to s == -2, ns == 89999999.
		 I.e., truncate time stamps towards minus infinity while
		 converting them to internal form.  */
	      ns += trailing_nonzero;
	      if (ns != 0)
		{
		  if (s == TYPE_MINIMUM (time_t))
		    return decode_time_range;
		  s--;
		  ns = BILLION - ns;
		}
	    }
	}

      if (! *p)
	{
	  ts->tv_sec = s;
	  ts->tv_nsec = ns;
	  return decode_time_success;
	}
    }

  return decode_time_bad_header;
}

static bool
decode_time (struct timespec *ts, char const *arg, char const *keyword)
{
  switch (_decode_time (ts, arg, keyword))
    {
    case decode_time_success:
      return true;
    case decode_time_bad_header:
      ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
	      keyword, arg));
      return false;
    case decode_time_range:
      out_of_range_header (keyword, arg, - (uintmax_t) TYPE_MINIMUM (time_t),
			   TYPE_MAXIMUM (time_t));
      return false;
    }
  return true;
}

static void
code_num (uintmax_t value, char const *keyword, struct xheader *xhdr)
{
  char sbuf[UINTMAX_STRSIZE_BOUND];
  xheader_print (xhdr, keyword, umaxtostr (value, sbuf));
}

static bool
decode_num (uintmax_t *num, char const *arg, uintmax_t maxval,
	    char const *keyword)
{
  uintmax_t u;
  char *arg_lim;

  if (! (ISDIGIT (*arg)
	 && (errno = 0, u = strtoumax (arg, &arg_lim, 10), !*arg_lim)))
    {
      ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
	      keyword, arg));
      return false;
    }

  if (! (u <= maxval && errno != ERANGE))
    {
      out_of_range_header (keyword, arg, 0, maxval);
      return false;
    }

