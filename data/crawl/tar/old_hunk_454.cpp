| (all blank, or nonoctal).						  |
`------------------------------------------------------------------------*/

long
from_oct (int digs, char *where)
{
  long value;

  while (ISSPACE (*where))
    {				/* skip spaces */
      where++;
      if (--digs <= 0)
	return -1;		/* all blank field */
    }
  value = 0;
  while (digs > 0 && ISODIGIT (*where))
    {
      /* Scan til nonoctal.  */

      value = (value << 3) | (*where++ - '0');
      --digs;
    }

  if (digs > 0 && *where && !ISSPACE (*where))
    return -1;			/* ended on non-space/nul */

  return value;
}

#if !USE_OLD_CTIME
