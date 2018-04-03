     /* Do it only once.  */
     return;
 
-  printf ("%sGNU Make %s", precede, version_string);
+  printf ("%sGNU Make version %s", precede, version_string);
   if (remote_description != 0 && *remote_description != '\0')
     printf ("-%s", remote_description);
 
-  printf (_(" (%s)\n\
-%s  by Richard Stallman and Roland McGrath.\n\
+  printf (_(", by Richard Stallman and Roland McGrath.\n\
+%sBuilt for %s\n\
 %sCopyright (C) 1988, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99\n\
 %s\tFree Software Foundation, Inc.\n\
 %sThis is free software; see the source for copying conditions.\n\
 %sThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A\n\
 %sPARTICULAR PURPOSE.\n\n\
 %sReport bugs to <bug-make@gnu.org>.\n\n"),
-          make_host,
-	  precede, precede, precede, precede, precede, precede, precede);
+          precede, make_host,
+	  precede, precede, precede, precede, precede, precede);
 
   printed_version = 1;
 
