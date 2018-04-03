 
   /* TRANSLATORS: When available, an actual copyright character
      (circle-c) should be used in preference to "(C)". */
-  if (fputs (_("\
-Copyright (C) 2011 Free Software Foundation, Inc.\n"), stdout) < 0)
+  if (printf (_("\
+Copyright (C) %s Free Software Foundation, Inc.\n"), "2014") < 0)
     exit (3);
   if (fputs (_("\
 License GPLv3+: GNU GPL version 3 or later\n\
