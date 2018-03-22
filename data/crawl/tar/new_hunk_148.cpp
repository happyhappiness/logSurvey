}

static void
code_time (struct timespec t, char const *keyword, struct xheader *xhdr)
{
  time_t s = t.tv_sec;
  int ns = t.tv_nsec;
  char sbuf[1/*"-"*/ + UINTMAX_STRSIZE_BOUND + 1/*"."*/ + LOG10_BILLION];
  char *np;
  bool negative = s < 0;

  if (negative && ns != 0)
    {
      s++;
      ns = BILLION - ns;
    }

  np = umaxtostr (negative ? - (uintmax_t) s : (uintmax_t) s, sbuf + 1);
  if (negative)
    *--np = '-';
  code_ns_fraction (ns, sbuf + UINTMAX_STRSIZE_BOUND);
  xheader_print (xhdr, keyword, np);
}

static bool
decode_time (struct timespec *ts, char const *arg, char const *keyword)
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
	    goto out_of_range;
	  s = i;
	}
      else
	{
	  uintmax_t i = strtoumax (arg, &arg_lim, 10);
	  if (TYPE_MAXIMUM (time_t) < i)
	    goto out_of_range;
	  s = i;
	}

      p = arg_lim;

      if (errno == ERANGE)
	goto out_of_range;

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
		    goto out_of_range;
		  s--;
		  ns = BILLION - ns;
		}
	    }
	}

      if (! *p)
	{
	  ts->tv_sec = s;
	  ts->tv_nsec = ns;
	  return true;
	}
    }

  ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
	  keyword, arg));
  return false;

 out_of_range:
  out_of_range_header (keyword, arg, - (uintmax_t) TYPE_MINIMUM (time_t),
		       TYPE_MAXIMUM (time_t));
  return false;
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

  *num = u;
  return true;
}

static void
