   if (show_version)
     {
       printf ("genfile (GNU %s) %s\n", PACKAGE, VERSION);
-      fputs (_("\
-\n\
-Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.\n"),
-	     stdout);
-      fputs (_("\
-This is free software; see the source for copying conditions.  There is NO\n\
-warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"),
-	     stdout);
-      fputs (_("\
-\n\
-Written by Fran�ois Pinard <pinard@iro.umontreal.ca>.\n"),
-	     stdout);
+      printf (_("Copyright (C) %d Free Software Foundation, Inc.\n"), 2003);
+      puts (_("\
+This program comes with NO WARRANTY, to the extent permitted by law.\n\
+You may redistribute it under the terms of the GNU General Public License;\n\
+see the file named COPYING for details."));
+
+      /* Note to translator: Please translate "F. Pinard" to "François
+	 Pinard" if "ç" (c-with-cedilla) is available in the
+	 translation's character set and encoding.  */
+      puts (_("Written by F. Pinard."));
+
       exit (EXIT_SUCCESS);
     }
 
