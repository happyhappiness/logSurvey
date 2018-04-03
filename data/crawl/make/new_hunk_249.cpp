      const char *p;

      if (!conditionals->if_cmds)
        EXTRACMD ();

      o = conditionals->if_cmds - 1;

      if (conditionals->seen_else[o])
        O (fatal, flocp, _("only one 'else' per conditional"));

      /* Change the state of ignorance.  */
      switch (conditionals->ignoring[o])
