   return buf;
 }
 #endif
-
-/* Print an error message from errno.  */
-
-void
-perror_with_name (const char *str, const char *name)
-{
-  error (NILF, _("%s%s: %s"), str, name, strerror (errno));
-}
-
-/* Print an error message from errno and exit.  */
-
-void
-pfatal_with_name (const char *name)
-{
-  fatal (NILF, _("%s: %s"), name, strerror (errno));
-
-  /* NOTREACHED */
-}
 
 /* Like malloc but get fatal error if memory is exhausted.  */
 /* Don't bother if we're using dmalloc; it provides these for us.  */
