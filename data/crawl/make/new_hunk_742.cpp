	 ignoring anything, since they control what we will do with
	 following lines.  */

      if (!in_ignored_define)
	{
 	  int i = conditional_line (p, len, fstart);
          if (i != -2)
            {
              if (i == -1)
                fatal (fstart, _("invalid syntax in conditional"));

              ignoring = i;
              continue;
            }
	}

      if (word1eq ("endef"))
