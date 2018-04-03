   switch (errno)
     {
     case ENOENT:
-      error (NILF, _("%s: Command not found"), argv[0]);
+      OS (error, NILF, _("%s: Command not found"), argv[0]);
       break;
     case ENOEXEC:
       {
