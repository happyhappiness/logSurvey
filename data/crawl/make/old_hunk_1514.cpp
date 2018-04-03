      fputs ("\n# General (`VPATH' variable) search path:\n# ", stdout);

      for (i = 0; path[i] != 0; ++i)
	printf ("%s%c", path[i], path[i + 1] == 0 ? '\n' : ':');
    }
}
