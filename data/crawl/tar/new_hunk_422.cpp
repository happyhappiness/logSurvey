
struct link *linklist = NULL;	/* points to first link in list */

/* Base 64 digits; see Internet RFC 2045 Table 1.  */
char const base_64_digits[64] =
{
  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
  'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};
#define base_8_digits (base_64_digits + 26 * 2)

/* The maximum uintmax_t value that can be represented with DIGITS digits,
   assuming that each digit is BITS_PER_DIGIT wide.  */
#define MAX_VAL_WITH_DIGITS(digits, bits_per_digit) \
   ((digits) * (bits_per_digit) < sizeof (uintmax_t) * CHAR_BIT \
    ? ((uintmax_t) 1 << ((digits) * (bits_per_digit))) - 1 \
    : (uintmax_t) -1)

/* Convert VALUE to a representation suitable for tar headers,
   using base 1 << BITS_PER_DIGIT.
   Use the digits in DIGIT_CHAR[0] ... DIGIT_CHAR[base - 1].
   Output to buffer WHERE with size SIZE.
   The result is undefined if SIZE is 0 or if VALUE is too large to fit.  */

static void
to_base (uintmax_t value, int bits_per_digit, char const *digit_char,
	 char *where, size_t size)
{
  uintmax_t v = value;
  size_t i = size;
  unsigned digit_mask = (1 << bits_per_digit) - 1;

  do
    {
      where[--i] = digit_char[v & digit_mask];
      v >>= bits_per_digit;
    }
  while (i);
}

/* NEGATIVE is nonzero if VALUE was negative before being cast to
   uintmax_t; its original bitpattern can be deduced from VALSIZE, its
   original size before casting.  Convert VALUE to external form,
   using SUBSTITUTE (...)  if VALUE won't fit.  Output to buffer WHERE
   with size SIZE.  TYPE is the kind of value being output (useful for
   diagnostics).  Prefer the POSIX format of SIZE - 1 octal digits
   (with leading zero digits), followed by '\0'.  If this won't work,
   and if GNU format is allowed, use '+' or '-' followed by SIZE - 1
   base-64 digits.  If neither format works, use SUBSTITUTE (...)
   instead.  Pass to SUBSTITUTE the address of an 0-or-1 flag
   recording whether the substitute value is negative.  */

static void
to_chars (int negative, uintmax_t value, size_t valsize,
	  uintmax_t (*substitute) PARAMS ((int *)),
	  char *where, size_t size, const char *type)
{
  uintmax_t v = negative ? -value : value;

  if (! negative && v <= MAX_VAL_WITH_DIGITS (size - 1, LG_8))
    {
      where[size - 1] = '\0';
      to_base (v, LG_8, base_8_digits, where, size - 1);
    }
  else if (v <= MAX_VAL_WITH_DIGITS (size - 1, LG_64)
	   && archive_format == GNU_FORMAT)
    {
      where[0] = negative ? '-' : '+';
      to_base (v, LG_64, base_64_digits, where + 1, size - 1);
    }
  else if (negative
	   && archive_format != GNU_FORMAT
	   && valsize * CHAR_BIT <= (size - 1) * LG_8)
    {
      where[size - 1] = '\0';
      to_base (value & MAX_VAL_WITH_DIGITS (valsize * CHAR_BIT, 1),
	       LG_8, base_8_digits, where, size - 1);
    }
  else
    {
      uintmax_t maxval = (archive_format == GNU_FORMAT
			  ? MAX_VAL_WITH_DIGITS (size - 1, LG_64)
			  : MAX_VAL_WITH_DIGITS (size - 1, LG_8));
      char buf1[UINTMAX_STRSIZE_BOUND + 1];
      char buf2[UINTMAX_STRSIZE_BOUND + 1];
      char buf3[UINTMAX_STRSIZE_BOUND + 1];
      char *value_string = STRINGIFY_BIGINT (v, buf1 + 1);
      char *maxval_string = STRINGIFY_BIGINT (maxval, buf2 + 1);
      char const *minval_string =
	(archive_format == GNU_FORMAT
	 ? "0"
	 : (maxval_string[-1] = '-', maxval_string - 1));
      if (negative)
	*--value_string = '-';
      if (substitute)
	{
	  int negsub;
	  uintmax_t sub = substitute (&negsub) & maxval;
	  uintmax_t s = (negsub &= archive_format == GNU_FORMAT) ? -sub : sub;
	  char *sub_string = STRINGIFY_BIGINT (s, buf3 + 1);
	  if (negsub)
	    *--sub_string = '-';
	  WARN ((0, 0, _("%s value %s out of range %s..%s; substituting %s"),
		 type, value_string, minval_string, maxval_string,
		 sub_string));
	  to_chars (negsub, s, valsize, NULL, where, size, type);
	}
      else
	ERROR ((0, 0, _("%s value %s out of range %s..%s"),
		type, value_string, minval_string, maxval_string));
    }
}

static uintmax_t
gid_substitute (int *negative)
{
  gid_t r;
#ifdef GID_NOBODY
  r = GID_NOBODY;
#else
  static gid_t gid_nobody;
  if (!gid_nobody && !gname_to_gid ("nobody", &gid_nobody))
    gid_nobody = -2;
  r = gid_nobody;
#endif
  *negative = r < 0;
  return r;
}

void
gid_to_chars (gid_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, gid_substitute, p, s, "gid_t");
}

void
major_to_chars (major_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, NULL, p, s, "major_t");
}

void
minor_to_chars (minor_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, NULL, p, s, "minor_t");
}

void
mode_to_chars (mode_t v, char *p, size_t s)
{
  /* In the common case where the internal and external mode bits are the same,
     propagate all unknown bits to the external mode.
     This matches historical practice.
     Otherwise, just copy the bits we know about.  */
  int negative;
  uintmax_t u;
  if (S_ISUID == TSUID && S_ISGID == TSGID && S_ISVTX == TSVTX
      && S_IRUSR == TUREAD && S_IWUSR == TUWRITE && S_IXUSR == TUEXEC
      && S_IRGRP == TGREAD && S_IWGRP == TGWRITE && S_IXGRP == TGEXEC
      && S_IROTH == TOREAD && S_IWOTH == TOWRITE && S_IXOTH == TOEXEC)
    {
      negative = v < 0;
      u = v;
    }
  else
    {
      negative = 0;
      u = ((v & S_ISUID ? TSUID : 0)
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
	   | (v & S_IXOTH ? TOEXEC : 0));
    }
  to_chars (negative, u, sizeof v, NULL, p, s, "mode_t");
}

void
off_to_chars (off_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, NULL, p, s, "off_t");
}

void
size_to_chars (size_t v, char *p, size_t s)
{
  to_chars (0, (uintmax_t) v, sizeof v, NULL, p, s, "size_t");
}

void
time_to_chars (time_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, NULL, p, s, "time_t");
}

static uintmax_t
uid_substitute (int *negative)
{
  uid_t r;
#ifdef UID_NOBODY
  r = UID_NOBODY;
#else
  static uid_t uid_nobody;
  if (!uid_nobody && !uname_to_uid ("nobody", &uid_nobody))
    uid_nobody = -2;
  r = uid_nobody;
#endif
  *negative = r < 0;
  return r;
}

void
uid_to_chars (uid_t v, char *p, size_t s)
{
  to_chars (v < 0, (uintmax_t) v, sizeof v, uid_substitute, p, s, "uid_t");
}

void
uintmax_to_chars (uintmax_t v, char *p, size_t s)
{
  to_chars (0, v, sizeof v, NULL, p, s, "uintmax_t");
}

/* Writing routines.  */
