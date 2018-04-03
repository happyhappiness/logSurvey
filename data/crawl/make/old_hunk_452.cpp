  if (cmdtype == c_endif)
    {
      if (*line != '\0')
	EXTRANEOUS ();

      if (!conditionals->if_cmds)
	fatal (flocp, _("extraneous '%s'"), cmdname);

      --conditionals->if_cmds;

