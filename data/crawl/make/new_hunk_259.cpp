        switch (glob (name, GLOB_NOSORT|GLOB_ALTDIRFUNC, NULL, &gl))
          {
          case GLOB_NOSPACE:
            OUT_OF_MEM();

          case 0:
            /* Success.  */
