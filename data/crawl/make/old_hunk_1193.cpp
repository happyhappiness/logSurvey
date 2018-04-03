    }

  if (vpaths == 0)
    puts ("# No `vpath' search paths.");
  else
    printf ("\n# %u `vpath' search paths.\n", nvpaths);

  if (general_vpath == 0)
    puts ("\n# No general (`VPATH' variable) search path.");
  else
    {
      register char **path = general_vpath->searchpath;
      register unsigned int i;

      fputs ("\n# General (`VPATH' variable) search path:\n# ", stdout);

      for (i = 0; path[i] != 0; ++i)
	printf ("%s%c", path[i],
