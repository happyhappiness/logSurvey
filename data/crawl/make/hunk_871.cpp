 
 void
 pfatal_with_name (name)
-     char *name;
+     const char *name;
 {
   fatal (NILF, "%s: %s", name, strerror (errno));
 
