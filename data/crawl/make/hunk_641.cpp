     /* Do it only once.  */
     return;
 
+  printf ("%sGNU Make %s\n", precede, version_string);
+
+  if (!remote_description || *remote_description == '\0')
+    printf (_("%sBuilt for %s\n"), precede, make_host);
+  else
+    printf (_("%sBuilt for %s (%s)\n"),
+            precede, make_host, remote_description);
+
   /* Print this untranslated.  The coding standards recommend translating the
      (C) to the copyright symbol, but this string is going to change every
      year, and none of the rest of it should be translated (including the
      word "Copyright", so it hardly seems worth it.  */
 
-  printf ("%sGNU Make %s\n\
-%sCopyright (C) 2006  Free Software Foundation, Inc.\n",
-          precede, version_string, precede);
+  printf ("%sCopyright (C) 2007  Free Software Foundation, Inc.\n", precede);
 
-  printf (_("%sThis is free software; see the source for copying conditions.\n\
-%sThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A\n\
-%sPARTICULAR PURPOSE.\n"),
+  printf (_("%sLicense GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n\
+%sThis is free software: you are free to change and redistribute it.\n\
+%sThere is NO WARRANTY, to the extent permitted by law.\n"),
             precede, precede, precede);
 
-  if (!remote_description || *remote_description == '\0')
-    printf (_("\n%sThis program built for %s\n"), precede, make_host);
-  else
-    printf (_("\n%sThis program built for %s (%s)\n"),
-            precede, make_host, remote_description);
-
   printed_version = 1;
 
   /* Flush stdout so the user doesn't have to wait to see the
