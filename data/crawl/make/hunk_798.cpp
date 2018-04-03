 %sPARTICULAR PURPOSE.\n"),
             precede, precede, precede);
 
+  if (!remote_description || *remote_description == '\0')
+    printf (_("\n%sThis program built for %s\n"), precede, make_host);
+  else
+    printf (_("\n%sThis program built for %s (%s)\n"),
+            precede, make_host, remote_description);
+
   printed_version = 1;
 
   /* Flush stdout so the user doesn't have to wait to see the
