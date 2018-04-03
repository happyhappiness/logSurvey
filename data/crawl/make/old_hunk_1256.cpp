
  fputs ("#  commands to execute", stdout);

  if (cmds->filename == 0)
    puts (" (built-in):");
  else
    printf (" (from `%s', line %u):\n", cmds->filename, cmds->lineno);

  s = cmds->commands;
  while (*s != '\0')
