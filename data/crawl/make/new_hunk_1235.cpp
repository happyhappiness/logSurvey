      /* This can happen if a fatal error was detected while reading the
         makefiles and thus count_implicit_rule_limits wasn't called yet.  */
      if (num_pattern_rules != 0)
        fatal (NILF, "BUG: num_pattern_rules wrong!  %u != %u",
               num_pattern_rules, rules);
    }

