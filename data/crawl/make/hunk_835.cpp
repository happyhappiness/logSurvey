 pfatal_with_name (name)
      const char *name;
 {
-  fatal (NILF, "%s: %s", name, strerror (errno));
+  fatal (NILF, _("%s: %s"), name, strerror (errno));
 
   /* NOTREACHED */
 }
