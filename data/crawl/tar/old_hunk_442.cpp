
  if (v != 0)
    {
      char buf[UINTMAX_STRSIZE_BOUND];
      ERROR ((0, 0, _("%s value %s is too large to fit in a %u-bit field"),
	      type, STRINGIFY_BIGINT (value, buf),
	      (unsigned) ((size - 1) * 3)));
    }
}
void
gid_to_oct (gid_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "gid_t");
}
void
major_to_oct (major_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "major_t");
}
void
minor_to_oct (minor_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "minor_t");
}
void
mode_to_oct (mode_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "mode_t");
}
void
off_to_oct (off_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "off_t");
}
void
size_to_oct (size_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "size_t");
}
void
time_to_oct (time_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "time_t");
}
void
uid_to_oct (uid_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, p, s, "uid_t");
}
void
uintmax_to_oct (uintmax_t v, char *p, size_t s)
{
  to_oct (v, p, s, "uintmax_t");
}

/* Writing routines.  */
