#endif
      puts (" reference nonexistent subdirectories.");
    }

  if (num_pattern_rules != rules)
    fatal ("BUG: num_pattern_rules wrong!  %u != %u",
	   num_pattern_rules, rules);
}
