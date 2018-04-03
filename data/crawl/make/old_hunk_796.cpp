vms_handle_apos (char *p)
{
  int alast;
  int inside;

#define SEPCHARS ",/()= "

  inside = 0;

  while (*p != 0)
    {
      if (*p == '"')
	{
	  if (inside)
	    {
	      while ((alast > 0)
		    && (*p == '"'))
		{
		  p++;
		  alast--;
		}
	      if (alast == 0)
		inside = 0;
	      else
		{
		  fprintf (stderr, _("Syntax error, still inside '\"'\n"));
		  exit (3);
		}
	    }
	  else
	    {
	      p++;
	      if (strchr (SEPCHARS, *p))
		break;
	      inside = 1;
	      alast = 1;
	      while (*p == '"')
		{
		  alast++;
		  p++;
		}
	    }
	}
      else
