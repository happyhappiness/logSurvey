      else if (streq (name, ".SECONDEXPANSION"))
        second_expansion = 1;

      implicit_percent = find_percent_cached (&name);
      implicit |= implicit_percent != 0;

      if (implicit)
        {
          if (pattern != 0)
            fatal (flocp, _("mixed implicit and static pattern rules"));

          if (implicit_percent == 0)
            fatal (flocp, _("mixed implicit and normal rules"));

	  if (targets == 0)
	    {
	      max_targets = 5;
