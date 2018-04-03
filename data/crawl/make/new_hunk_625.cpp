{
  const char *s;

  fputs (_("#  recipe to execute"), stdout);

  if (cmds->fileinfo.filenm == 0)
    puts (_(" (built-in):"));
