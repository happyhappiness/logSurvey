}

/*------------------------------------------------------------------------.
| Quick and dirty octal conversion.  Result is -1 if the field is invalid |
| (all blank, or nonoctal).						  |
`------------------------------------------------------------------------*/

static uintmax_t
from_oct (const char *where0, size_t digs0, const char *type, uintmax_t maxval)
{
  uintmax_t value;
  const char *where = where0;
  size_t digs = digs0;

  for (;;)
    {
      if (digs == 0)
	{
	  if (type)
	    ERROR ((0, 0, _("Blanks in header where octal %s value expected"),
		    type));
	  return -1;
	}
      if (!ISSPACE ((unsigned char) *where))
	break;
      where++;
      digs--;
    }

  value = 0;
  while (digs != 0 && ISODIGIT (*where))
    {
      /* Scan til nonoctal.  */

      if (value << 3 >> 3 != value)
	goto out_of_range;
      value = (value << 3) | (*where++ - '0');
      --digs;
    }

  if (digs != 0 && *where && !ISSPACE ((unsigned char) *where))
    {
      if (type)
	{
