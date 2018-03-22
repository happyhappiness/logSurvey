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
