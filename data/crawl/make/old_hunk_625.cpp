{
  const char *s;

  fputs (_("#  commands to execute"), stdout);

  if (cmds->fileinfo.filenm == 0)
    puts (_(" (built-in):"));
