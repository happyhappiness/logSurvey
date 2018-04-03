  /* Finally, set the corresponding CMDS->lines_flags elements and the
     CMDS->any_recurse flag.  */

  if (nlines > USHRT_MAX)
    fatal (&cmds->fileinfo, _("Recipe has too many lines (%ud)"), nlines);

  cmds->ncommand_lines = nlines;
  cmds->command_lines = lines;

