      printf ("\n# %u implicit rules, %u", rules, terminal);
#ifndef	NO_FLOAT
      printf (" (%.1f%%)", (double) terminal / (double) rules * 100.0);
#endif
      puts (" terminal.");
    }
