 void
 perror_with_name (const char *str, const char *name)
 {
-  error (NILF, _("%s%s: %s"), str, name, strerror (errno));
+  const char *err = strerror (errno);
+  OSSS (error, NILF, _("%s%s: %s"), str, name, err);
 }
 
 /* Print an error message from errno and exit.  */
