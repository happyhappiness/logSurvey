    {
      if (digs == 0)
	{
	  ERROR ((0, 0, _("Blanks in header where octal %s value expected"),
		  type));
	  return -1;
	}
      if (!ISSPACE (*where))
