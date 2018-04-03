  register unsigned int rules, terminal;
  register struct rule *r;

  puts (_("\n# Implicit Rules"));

  rules = terminal = 0;
  for (r = pattern_rules; r != 0; r = r->next)
