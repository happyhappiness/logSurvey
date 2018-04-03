  puts (_("\n# Variables\n"));

  print_variable_set (&global_variable_set, "");

  puts (_("\n# Pattern-specific Variable Values"));

  {
    struct pattern_var *p;
    int rules = 0;

    for (p = pattern_vars; p != 0; p = p->next)
      {
        ++rules;
        printf ("\n%s :\n", p->target);
        print_variable (&p->variable, "# ");
      }

    if (rules == 0)
      puts (_("\n# No pattern-specific variable values."));
    else
      printf (_("\n# %u pattern-specific variable values"), rules);
  }
}


