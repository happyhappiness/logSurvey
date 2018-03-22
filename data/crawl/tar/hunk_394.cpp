 
   if (show_version)
     {
-      printf ("tar (GNU %s) %s\n", PACKAGE, VERSION);
-      fputs (_("\
-\n\
-Copyright 1988, 92,93,94,95,96,97,98, 1999 Free Software Foundation, Inc.\n"),
-	     stdout);
-      fputs (_("\
-This is free software; see the source for copying conditions.  There is NO\n\
-warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Written by John Gilmore and Jay Fenlason.\n"),
-	     stdout);
+      printf ("tar (GNU %s) %s\n%s\n%s\n%s\n", PACKAGE, VERSION,
+	      "Copyright 1999 Free Software Foundation, Inc.",
+	      _("\
+This program comes with NO WARRANTY, to the extent permitted by law.\n\
+You may redistribute it under the terms of the GNU General Public License;\n\
+see the file named COPYING for details."),
+	      _("Written by John Gilmore and Jay Fenlason."));
       exit (TAREXIT_SUCCESS);
     }
 
