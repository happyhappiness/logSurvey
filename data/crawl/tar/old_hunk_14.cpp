    checkpoint_option = DEFAULT_CHECKPOINT;
}

static char *
expand_checkpoint_string (const char *input, bool do_write, unsigned cpn)
{
  const char *opstr = do_write ? gettext ("write") : gettext ("read");
  size_t opstrlen = strlen (opstr);
  char uintbuf[UINTMAX_STRSIZE_BOUND];
  char *cps = STRINGIFY_BIGINT (cpn, uintbuf);
  size_t cpslen = strlen (cps);
  const char *ip;
  char *op;
  char *output;
  size_t outlen = strlen (input); /* Initial guess */

  /* Fix the initial length guess */
  for (ip = input; (ip = strchr (ip, '%')) != NULL; )
    {
      switch (ip[1])
	{
	case 'u':
	  outlen += cpslen - 2;
	  break;

	case 's':
	  outlen += opstrlen - 2;
	}
      ip++;
    }

  output = xmalloc (outlen + 1);
  for (ip = input, op = output; *ip; )
    {
      if (*ip == '%')
	{
	  switch (*++ip)
	    {
	    case 'u':
	      op = stpcpy (op, cps);
	      break;

	    case 's':
	      op = stpcpy (op, opstr);
	      break;

	    default:
	      *op++ = '%';
	      *op++ = *ip;
	      break;
	    }
	  ip++;
	}
      else
	*op++ = *ip++;
    }
  *op = 0;
  return output;
}

static void
