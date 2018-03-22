
  if (show_version)
    {
      printf ("tar (GNU %s) %s\n%s\n%s\n%s\n", PACKAGE, VERSION,
	      "Copyright 1999 Free Software Foundation, Inc.",
	      _("\
This program comes with NO WARRANTY, to the extent permitted by law.\n\
You may redistribute it under the terms of the GNU General Public License;\n\
see the file named COPYING for details."),
	      _("Written by John Gilmore and Jay Fenlason."));
      exit (TAREXIT_SUCCESS);
    }

