	      set_quoting_style (o, c_quoting_style);
	    }

	  for (digs = digs0;  digs && ! where0[digs - 1];  digs--)
	    continue;
	  quotearg_buffer (buf, sizeof buf, where0, digs, o);
	  ERROR ((0, 0,
		  _("Header contains %.*s where octal %s value expected"),
		  (int) sizeof buf, buf, type));
	}

      return -1;
    }

  if (value <= maxval)
    return value;

 out_of_range:
  if (type)
    ERROR ((0, 0, _("Octal value `%.*s' is out of range for %s"),
	    (int) digs0, where0, type));
  return -1;
}
gid_t
gid_from_oct (const char *p, size_t s)
{
  return from_oct (p, s, "gid_t", (uintmax_t) TYPE_MAXIMUM (gid_t));
}
major_t
major_from_oct (const char *p, size_t s)
{
  return from_oct (p, s, "major_t", (uintmax_t) TYPE_MAXIMUM (major_t));
}
minor_t
minor_from_oct (const char *p, size_t s)
{
  return from_oct (p, s, "minor_t", (uintmax_t) TYPE_MAXIMUM (minor_t));
}
mode_t
mode_from_oct (const char *p, size_t s)
{
  /* Do not complain about unrecognized mode bits.  */
  unsigned u = from_oct (p, s, "mode_t", TYPE_MAXIMUM (uintmax_t));
  return ((u & TSUID ? S_ISUID : 0)
	  | (u & TSGID ? S_ISGID : 0)
	  | (u & TSVTX ? S_ISVTX : 0)
