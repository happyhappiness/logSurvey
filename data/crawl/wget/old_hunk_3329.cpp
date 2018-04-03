
static int simple_atof PARAMS ((const char *, const char *, double *));

/* Parse VAL as a number and set its value to CLOSURE (which should
   point to a long int).

   By default, the value is assumed to be in bytes.  If "K", "M", or
   "G" are appended, the value is multiplied with 1<<10, 1<<20, or
   1<<30, respectively.  Floating point values are allowed and are
   cast to integer before use.  The idea is to be able to use things
   like 1.5k instead of "1536".

   The string "inf" is returned as 0.

   In case of error, 0 is returned and memory pointed to by CLOSURE
   remains unmodified.  */

static int
cmd_bytes (const char *com, const char *val, void *closure)
{
  long mult;
  double number;
  const char *end = val + strlen (val);

  /* Check for "inf".  */
  if (0 == strcmp (val, "inf"))
    {
      *(long *)closure = 0;
      return 1;
    }

  /* Strip trailing whitespace.  */
  while (val < end && ISSPACE (end[-1]))
    --end;

  if (val == end)
    {
    err:
      fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
	       exec_name, com, val);
      return 0;
    }

  switch (TOLOWER (end[-1]))
    {
    case 'k':
      --end, mult = 1L<<10;
      break;
    case 'm':
      --end, mult = 1L<<20;
      break;
    case 'g':
      --end, mult = 1L<<30;
      break;
    default:
      /* Not a recognized suffix: assume it belongs to the number.
	 (If not, atof simple_atof will raise an error.)  */
      mult = 1;
    }

