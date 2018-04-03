  putchar ('\n');

  if (f->precious)
    puts (_("#  Precious file (dependency of .PRECIOUS)."));
  if (f->phony)
    puts (_("#  Phony target (dependency of .PHONY)."));
  if (f->cmd_target)
    puts (_("#  Command-line target."));
  if (f->dontcare)
