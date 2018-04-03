  /* All user options have now been processed, so it's now safe to do
     interoption dependency checks. */

  if (opt.reclevel == 0)
      opt.reclevel = INFINITE_RECURSION; /* see recur.h for commentary */

