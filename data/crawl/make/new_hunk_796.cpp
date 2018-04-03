vms_handle_apos (char *p)
{
  int alast;

#define SEPCHARS ",/()= "

  alast = 0;

  while (*p != 0)
    {
      if (*p == '"')
	{
          if (alast)
            {
              alast = 0;
              p++;
	    }
	  else
	    {
	      p++;
	      if (strchr (SEPCHARS, *p))
		break;
	      alast = 1;
	    }
	}
      else
