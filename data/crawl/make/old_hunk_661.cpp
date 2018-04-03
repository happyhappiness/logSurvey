      else if (streq (name, ".SECONDEXPANSION"))
        second_expansion = 1;

      implicit_percent = find_percent (name);
      implicit |= implicit_percent != 0;

      if (implicit && pattern != 0)
	fatal (flocp, _("mixed implicit and static pattern rules"));

      if (implicit && implicit_percent == 0)
	fatal (flocp, _("mixed implicit and normal rules"));

      if (implicit)
	{
	  if (targets == 0)
	    {
	      max_targets = 5;
