   fclose (fp);
 }
 
-/* Mapper for save_cookies callable by hash_table_map.  VALUE points
-   to the head in a chain of cookies.  The function prints the entire
-   chain.  */
-
-static int
-save_cookies_mapper (void *key, void *value, void *arg)
-{
-  FILE *fp = (FILE *)arg;
-  char *domain = (char *)key;
-  struct cookie *cookie = (struct cookie *)value;
-  for (; cookie; cookie = cookie->next)
-    {
-      if (!cookie->permanent && !opt.keep_session_cookies)
-	continue;
-      if (cookie_expired_p (cookie))
-	continue;
-      if (!cookie->domain_exact)
-	fputc ('.', fp);
-      fputs (domain, fp);
-      if (cookie->port != PORT_ANY)
-	fprintf (fp, ":%d", cookie->port);
-      fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
-	       cookie->domain_exact ? "FALSE" : "TRUE",
-	       cookie->path, cookie->secure ? "TRUE" : "FALSE",
-	       (double)cookie->expiry_time,
-	       cookie->attr, cookie->value);
-      if (ferror (fp))
-	return 1;		/* stop mapping */
-    }
-  return 0;
-}
-
 /* Save cookies, in format described above, to FILE. */
 
 void
 cookie_jar_save (struct cookie_jar *jar, const char *file)
 {
   FILE *fp;
+  hash_table_iterator iter;
 
   DEBUGP (("Saving cookies to %s.\n", file));
 
