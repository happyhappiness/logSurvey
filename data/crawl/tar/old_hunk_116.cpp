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
