}

static void
code_time (time_t t, unsigned long nano,
	   char const *keyword, struct xheader *xhdr)
{
  char sbuf[200];
  size_t s = format_uintmax (t, NULL, 0);
  if (s + 11 >= sizeof sbuf)
    return;
  format_uintmax (t, sbuf, s);
  sbuf[s++] = '.';
  s += format_uintmax (nano, sbuf + s, 9);
  sbuf[s] = 0;
  xheader_print (xhdr, keyword, sbuf);
}

static void
decode_time (char const *arg, time_t *secs, unsigned long *nsecs)
{
  uintmax_t u;
  char *p;
  if (xstrtoumax (arg, &p, 10, &u, "") == LONGINT_OK)
    {
      *secs = u;
      if (*p == '.' && xstrtoumax (p+1, NULL, 10, &u, "") == LONGINT_OK)
	*nsecs = u;
    }
}

static void
code_num (uintmax_t value, char const *keyword, struct xheader *xhdr)
{
  char sbuf[100];
  size_t s = format_uintmax (value, NULL, 0);
  format_uintmax (value, sbuf, s);
  sbuf[s] = 0;
  xheader_print (xhdr, keyword, sbuf);
}

static void
