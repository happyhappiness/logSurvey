    puts (_("\n# No implicit rules."));
  else
    {
      printf (_("\n# %u implicit rules, %u (%.1f%%) terminal."),
              rules, terminal, (double) terminal / (double) rules * 100.0);
    }

  if (num_pattern_rules != rules)
