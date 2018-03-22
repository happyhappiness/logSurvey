	      set_quoting_style (o, c_quoting_style);
	    }

	  while (where0 != lim && ! lim[-1])
	    lim--;
	  quotearg_buffer (buf, sizeof buf, where0, lim - where, o);
	  ERROR ((0, 0,
		  _("Header contains `%.*s' where numeric %s value expected"),
		  (int) sizeof buf, buf, type));
	}

      return -1;
    }

  if (value <= (negative ? minus_minval : maxval))
    return negative ? -value : value;

 out_of_range:
  if (type)
    ERROR ((0, 0, _("Numeric value `%.*s' is out of range for %s"),
	    (int) digs, where0, type));
  return -1;
}

gid_t
gid_from_chars (const char *p, size_t s)
{
  return from_chars (p, s, "gid_t",
		     - (uintmax_t) TYPE_MINIMUM (gid_t),
		     (uintmax_t) TYPE_MAXIMUM (gid_t));
}

major_t
major_from_chars (const char *p, size_t s)
{
  return from_chars (p, s, "major_t",
		     - (uintmax_t) TYPE_MINIMUM (major_t),
		     (uintmax_t) TYPE_MAXIMUM (major_t));
}

minor_t
minor_from_chars (const char *p, size_t s)
{
  return from_chars (p, s, "minor_t",
		     - (uintmax_t) TYPE_MINIMUM (minor_t),
		     (uintmax_t) TYPE_MAXIMUM (minor_t));
}

mode_t
mode_from_chars (const char *p, size_t s)
{
  /* Do not complain about unrecognized mode bits.  */
  unsigned u = from_chars (p, s, "mode_t",
			   - (uintmax_t) TYPE_MINIMUM (mode_t),
			   TYPE_MAXIMUM (uintmax_t));
  return ((u & TSUID ? S_ISUID : 0)
	  | (u & TSGID ? S_ISGID : 0)
	  | (u & TSVTX ? S_ISVTX : 0)
