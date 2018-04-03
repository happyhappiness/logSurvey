      const char *p;

      if (!conditionals->if_cmds)
	fatal (flocp, _("extraneous `%s'"), cmdname);

      o = conditionals->if_cmds - 1;

      if (conditionals->seen_else[o])
        fatal (flocp, _("only one `else' per conditional"));

      /* Change the state of ignorance.  */
      switch (conditionals->ignoring[o])
