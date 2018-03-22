  if (show_version)
    {
      printf ("genfile (GNU %s) %s\n", PACKAGE, VERSION);
      printf (_("Copyright (C) %d Free Software Foundation, Inc.\n"), 2003);
      puts (_("\
This program comes with NO WARRANTY, to the extent permitted by law.\n\
You may redistribute it under the terms of the GNU General Public License;\n\
see the file named COPYING for details."));

      /* Note to translator: Please translate "F. Pinard" to "François
	 Pinard" if "ç" (c-with-cedilla) is available in the
	 translation's character set and encoding.  */
      puts (_("Written by F. Pinard."));

      exit (EXIT_SUCCESS);
    }

