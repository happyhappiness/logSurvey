      const char *p;

      if (!conditionals->if_cmds)
        fatal (flocp, _("extraneous '%s'"), cmdname);

      o = conditionals->if_cmds - 1;

