  xheader_print (xhdr, keyword, code_timespec (t, buf));
}

static bool
decode_time (struct timespec *ts, char const *arg, char const *keyword)
{
  char *arg_lim;
  struct timespec t = decode_timespec (arg, &arg_lim, true);

  if (! valid_timespec (t))
    {
      if (arg < arg_lim && !*arg_lim)
	out_of_range_header (keyword, arg, TYPE_MINIMUM (time_t),
			     TYPE_MAXIMUM (time_t));
      else
	ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
		keyword, arg));
      return false;
    }

  *ts = t;
  return true;
}

static void
code_signed_num (uintmax_t value, char const *keyword,
		 intmax_t minval, uintmax_t maxval, struct xheader *xhdr)
{
  char sbuf[SYSINT_BUFSIZE];
  xheader_print (xhdr, keyword, sysinttostr (value, minval, maxval, sbuf));
}

static void
code_num (uintmax_t value, char const *keyword, struct xheader *xhdr)
{
  code_signed_num (value, keyword, 0, UINTMAX_MAX, xhdr);
}

static bool
decode_signed_num (intmax_t *num, char const *arg,
		   intmax_t minval, uintmax_t maxval,
		   char const *keyword)
{
  char *arg_lim;
  intmax_t u = strtosysint (arg, &arg_lim, minval, maxval);

  if (errno == EINVAL || *arg_lim)
    {
      ERROR ((0, 0, _("Malformed extended header: invalid %s=%s"),
	      keyword, arg));
      return false;
    }

  if (errno == ERANGE)
    {
      out_of_range_header (keyword, arg, minval, maxval);
      return false;
    }

