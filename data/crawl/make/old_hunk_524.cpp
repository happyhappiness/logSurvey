    }

  if (vpaths == 0)
    puts (_("# No `vpath' search paths."));
  else
    printf (_("\n# %u `vpath' search paths.\n"), nvpaths);

  if (general_vpath == 0)
    puts (_("\n# No general (`VPATH' variable) search path."));
  else
    {
      const char **path = general_vpath->searchpath;
      unsigned int i;

      fputs (_("\n# General (`VPATH' variable) search path:\n# "), stdout);

      for (i = 0; path[i] != 0; ++i)
	printf ("%s%c", path[i],
