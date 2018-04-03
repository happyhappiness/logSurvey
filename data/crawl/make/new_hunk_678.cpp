    puts (_("\n# No general (`VPATH' variable) search path."));
  else
    {
      const char **path = general_vpath->searchpath;
      unsigned int i;

      fputs (_("\n# General (`VPATH' variable) search path:\n# "), stdout);

