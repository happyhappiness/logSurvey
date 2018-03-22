
struct link *linklist = NULL;	/* points to first link in list */


/*------------------------------------------------------------------------.
| Convert VALUE (with substitute SUBSTITUTE if VALUE is out of range)	  |
| into a size-SIZE field at WHERE, including a				  |
| trailing space.  For example, 3 for SIZE means two digits and a space.  |
|                                                                         |
| We assume the trailing NUL is already there and don't fill it in.  This |
| fact is used by start_header and finish_header, so don't change it!     |
`------------------------------------------------------------------------*/

/* Output VALUE in octal, using SUBSTITUTE if value won't fit.
   Output to buffer WHERE with size SIZE.
   TYPE is the kind of value being output (useful for diagnostics).
   Prefer SIZE - 1 octal digits (with leading '0's), followed by '\0';
   but if SIZE octal digits would fit, omit the '\0'.  */

static void
to_oct (uintmax_t value, uintmax_t substitute, char *where, size_t size, const char *type)
{
  uintmax_t v = value;
  size_t i = size;

# define MAX_OCTAL_VAL_WITH_DIGITS(digits) \
    ((digits) * 3 < sizeof (uintmax_t) * CHAR_BIT \
     ? ((uintmax_t) 1 << ((digits) * 3)) - 1 \
     : (uintmax_t) -1)

  /* Output a trailing NUL unless the value is too large.  */
  if (value <= MAX_OCTAL_VAL_WITH_DIGITS (size - 1))
    where[--i] = '\0';

  /* Produce the digits -- at least one.  */

  do
    {
      where[--i] = '0' + (int) (v & 7);	/* one octal digit */
      v >>= 3;
    }
  while (i != 0 && v != 0);

  /* Leading zeros, if necessary.  */
  while (i != 0)
    where[--i] = '0';

  if (v != 0)
    {
      uintmax_t maxval = MAX_OCTAL_VAL_WITH_DIGITS (size);
      char buf1[UINTMAX_STRSIZE_BOUND];
      char buf2[UINTMAX_STRSIZE_BOUND];
      char buf3[UINTMAX_STRSIZE_BOUND];
      char *value_string = STRINGIFY_BIGINT (value, buf1);
      char *maxval_string = STRINGIFY_BIGINT (maxval, buf2);
      if (substitute)
	{
	  substitute &= maxval;
	  WARN ((0, 0, _("%s value %s too large (max=%s); substituting %s"),
		 type, value_string, maxval_string,
		 STRINGIFY_BIGINT (substitute, buf3)));
	  to_oct (substitute, (uintmax_t) 0, where, size, type);
	}
      else
	ERROR ((0, 0, _("%s value %s too large (max=%s)"),
		type, value_string, maxval_string));
    }
}
#ifndef GID_NOBODY
#define GID_NOBODY 0
#endif
void
gid_to_oct (gid_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) GID_NOBODY, p, s, "gid_t");
}
void
major_to_oct (major_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "major_t");
}
void
minor_to_oct (minor_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "minor_t");
}
void
mode_to_oct (mode_t v, char *p, size_t s)
{
  /* In the common case where the internal and external mode bits are the same,
     propagate all unknown bits to the external mode.
     This matches historical practice.
     Otherwise, just copy the bits we know about.  */
  uintmax_t u =
    ((S_ISUID == TSUID && S_ISGID == TSGID && S_ISVTX == TSVTX
      && S_IRUSR == TUREAD && S_IWUSR == TUWRITE && S_IXUSR == TUEXEC
      && S_IRGRP == TGREAD && S_IWGRP == TGWRITE && S_IXGRP == TGEXEC
      && S_IROTH == TOREAD && S_IWOTH == TOWRITE && S_IXOTH == TOEXEC)
     ? v
     : ((v & S_ISUID ? TSUID : 0)
	| (v & S_ISGID ? TSGID : 0)
	| (v & S_ISVTX ? TSVTX : 0)
	| (v & S_IRUSR ? TUREAD : 0)
	| (v & S_IWUSR ? TUWRITE : 0)
	| (v & S_IXUSR ? TUEXEC : 0)
	| (v & S_IRGRP ? TGREAD : 0)
	| (v & S_IWGRP ? TGWRITE : 0)
	| (v & S_IXGRP ? TGEXEC : 0)
	| (v & S_IROTH ? TOREAD : 0)
	| (v & S_IWOTH ? TOWRITE : 0)
	| (v & S_IXOTH ? TOEXEC : 0)));
  to_oct (u, (uintmax_t) 0, p, s, "mode_t");
}
void
off_to_oct (off_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "off_t");
}
void
size_to_oct (size_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "size_t");
}
void
time_to_oct (time_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) 0, p, s, "time_t");
}
#ifndef UID_NOBODY
#define UID_NOBODY 0
#endif
void
uid_to_oct (uid_t v, char *p, size_t s)
{
  to_oct ((uintmax_t) v, (uintmax_t) UID_NOBODY, p, s, "uid_t");
}
void
uintmax_to_oct (uintmax_t v, char *p, size_t s)
{
  to_oct (v, (uintmax_t) 0, p, s, "uintmax_t");
}

/* Writing routines.  */
