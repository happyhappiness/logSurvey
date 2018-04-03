 {
   printf ("GNU Wget %s\n\n", version_string);
   fputs (_("\
-Copyright (C) 2005 Free Software Foundation, Inc.\n"), stdout);
+Copyright (C) 2006 Free Software Foundation, Inc.\n"), stdout);
   fputs (_("\
 This program is distributed in the hope that it will be useful,\n\
 but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n\
 GNU General Public License for more details.\n"), stdout);
   fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
-	 stdout);
+         stdout);
+  fputs (_("\nCurrently maintained by Mauro Tortonesi <mauro@ferrara.linux.it>.\n"),
+         stdout);
   exit (0);
 }
 
