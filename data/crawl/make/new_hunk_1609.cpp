  return pattern_search (file, 0, depth, 0);
}

#define DEBUGP2(msg, a1, a2)						      \
  do {									      \
    if (debug_flag)							      \
      { print_spaces (depth); printf (msg, a1, a2); fflush (stdout); }	      \
  } while (0)

/* Search the pattern rules for a rule with an existing dependency to make
   FILE.  If a rule is found, the appropriate commands and deps are put in FILE
