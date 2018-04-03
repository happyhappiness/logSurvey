 pfatal_with_name (name)
      char *name;
 {
-  fatal ("%s: %s", name, strerror (errno));
+  fatal (NILF, "%s: %s", name, strerror (errno));
 
   /* NOTREACHED */
 }
