

/*------------------------------------------------------------------------.
| Converts long VALUE into a DIGS-digit field at WHERE, including a       |
| trailing space and room for a NUL.  For example, 3 for DIGS 3 means one |
| digit, a space, and room for a NUL.                                     |
|                                                                         |
| We assume the trailing NUL is already there and don't fill it in.  This |
| fact is used by start_header and finish_header, so don't change it!     |
`------------------------------------------------------------------------*/

/* This should be equivalent to: sprintf (WHERE, "%*lo ", DIGS - 2, VALUE);
   except that sprintf fills in the trailing NUL and we don't.  */

void
to_oct (long value, int digs, char *where)
{
  --digs;			/* Trailing null slot is left alone */
  where[--digs] = ' ';		/* put in the space, though */

  /* Produce the digits -- at least one.  */

  do
    {
      where[--digs] = '0' + (char) (value & 7);	/* one octal digit */
      value >>= 3;
    }
  while (digs > 0 && value != 0);

  /* Leading spaces, if necessary.  */
  while (digs > 0)
    where[--digs] = ' ';
}

/* Writing routines.  */
