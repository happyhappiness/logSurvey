     }
 
   if (!remote_description || *remote_description == '\0')
-    fprintf (usageto, _("\nBuilt for %s"), make_host);
+    fprintf (usageto, _("\nThis program built for %s"), make_host);
   else
-    fprintf (usageto, "\nBuilt for %s (%s)", make_host, remote_description);
+    fprintf (usageto, "\nThis program built for %s (%s)", make_host, remote_description);
 
   fprintf (usageto, _("\nReport bugs to <bug-make@gnu.org>\n"));
 }
