    checkpoint_option = DEFAULT_CHECKPOINT;
}

static char *checkpoint_total_format[] = {
  "R",
  "W",
  "D"
};

static int
getwidth(FILE *fp)
{
  struct winsize ws;

  ws.ws_col = ws.ws_row = 0;
  if ((ioctl (fileno (fp), TIOCGWINSZ, (char *) &ws) < 0) || ws.ws_col == 0)
    {
      const char *col = getenv ("COLUMNS");
      if (col)
	return strtol (col, NULL, 10);
      else
	return 80;
    }
  return ws.ws_col;
}

static char *
getarg (const char *input, const char ** endp, char **argbuf, size_t *arglen)
{
  if (input[0] == '{')
    {
      char *p = strchr (input + 1, '}');
      if (p)
	{
	  size_t n = p - input;
	  if (n > *arglen)
	    {
	      *arglen = n;
	      *argbuf = xrealloc (*argbuf, *arglen);
	    }
	  n--;
	  memcpy (*argbuf, input + 1, n);
	  (*argbuf)[n] = 0;
	  *endp = p + 1;
	  return *argbuf;
	}
    }

  *endp = input;
  return NULL;
}


static void
format_checkpoint_string (FILE *fp, const char *input, bool do_write,
			  unsigned cpn)
{
  const char *opstr = do_write ? gettext ("write") : gettext ("read");
  char uintbuf[UINTMAX_STRSIZE_BOUND];
  char *cps = STRINGIFY_BIGINT (cpn, uintbuf);
  const char *ip;
  size_t len = 0;

  static char *argbuf = NULL;
  static size_t arglen = 0;
  char *arg = NULL;
  
  if (!input)
    {
      if (do_write)
	/* TRANSLATORS: This is a "checkpoint of write operation",
	 *not* "Writing a checkpoint".
	 E.g. in Spanish "Punto de comprobaci@'on de escritura",
	 *not* "Escribiendo un punto de comprobaci@'on" */
	input = gettext ("Write checkpoint %u");
      else
	/* TRANSLATORS: This is a "checkpoint of read operation",
	 *not* "Reading a checkpoint".
	 E.g. in Spanish "Punto de comprobaci@'on de lectura",
	 *not* "Leyendo un punto de comprobaci@'on" */
	input = gettext ("Read checkpoint %u");
    }
  
  for (ip = input; *ip; ip++)
    {
      if (*ip == '%')
	{
	  if (*++ip == '{')
	    {
	      arg = getarg (ip, &ip, &argbuf, &arglen);
	      if (!arg)
		{
		  fputc ('%', fp);
		  fputc (*ip, fp);
		  len += 2;
		  continue;
		}
	    }
	  switch (*ip)
	    {
	    case 'u':
	      fputs (cps, fp);
	      len += strlen (cps);
	      break;

	    case 's':
	      fputs (opstr, fp);
	      len += strlen (opstr);
	      break;

	    case 'd':
	      len += fprintf (fp, "%.0f", compute_duration ());
	      break;
	      
	    case 'T':
	      compute_duration ();
	      len += format_total_stats (fp, checkpoint_total_format, ',', 0);
	      break;

	    case 't':
	      {
		struct timeval tv;
		struct tm *tm;
		char *fmt = arg ? arg : "%c";

		gettimeofday (&tv, NULL);
		tm = localtime (&tv.tv_sec);
		len += fprintftime (fp, fmt, tm, 0, tv.tv_usec * 1000);
	      }
	      break;
	      
	    case '*':
	      {
		int w = arg ? strtoul (arg, NULL, 10) : getwidth (fp);
		for (; w > len; len++)
		  fputc (' ', fp);
	      }
	      break;
	      
	    default:
	      fputc ('%', fp);
	      fputc (*ip, fp);
	      len += 2;
	      break;
	    }
	  arg = NULL;
	}
      else
	{
	  fputc (*ip, fp);
	  if (*ip == '\r')
	    len = 0;
	  else
	    len++;
	}
    }
  fflush (fp);
}

static void
