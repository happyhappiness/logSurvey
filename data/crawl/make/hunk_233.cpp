 void
 pfatal_with_name (const char *name)
 {
-  fatal (NILF, _("%s: %s"), name, strerror (errno));
+  const char *err = strerror (errno);
+  OSS (fatal, NILF, _("%s: %s"), name, err);
 
   /* NOTREACHED */
 }
