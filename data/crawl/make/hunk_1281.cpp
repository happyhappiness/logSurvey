   switch (errno)
     {
     case ENOENT:
-      error ("%s: Command not found", argv[0]);
+      error (NILF, "%s: Command not found", argv[0]);
       break;
     case ENOEXEC:
       {
