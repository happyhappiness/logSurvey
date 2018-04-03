   else
     fprintf (stderr, "%s[%u]: *** ", program, makelevel);
 
-  VA_START(args, fmt);
-  VA_PRINTF (stderr, fmt, args);
-  VA_END (args);
+  va_start (args, fmt);
+  vfprintf (stderr, fmt, args);
+  va_end (args);
 
   fputs (_(".  Stop.\n"), stderr);
 
