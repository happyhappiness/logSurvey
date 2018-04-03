  if (r->terminal)
    putchar (':');

  print_prereqs (r->deps);

  if (r->cmds != 0)
    print_commands (r->cmds);
