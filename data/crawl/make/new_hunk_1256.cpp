
  fputs ("#  commands to execute", stdout);

  if (cmds->fileinfo.filenm == 0)
    puts (" (built-in):");
  else
    printf (" (from `%s', line %lu):\n",
            cmds->fileinfo.filenm, cmds->fileinfo.lineno);

  s = cmds->commands;
  while (*s != '\0')
