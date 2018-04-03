 rewrite_shorthand_url (const char *url)
 {
   const char *p;
+  char *ret;
 
   if (url_scheme (url) != SCHEME_INVALID)
     return NULL;
 
   /* Look for a ':' or '/'.  The former signifies NcFTP syntax, the
      latter Netscape.  */
-  for (p = url; *p && *p != ':' && *p != '/'; p++)
-    ;
-
+  p = strpbrk (url, ":/");
   if (p == url)
     return NULL;
 
   /* If we're looking at "://", it means the URL uses a scheme we
      don't support, which may include "https" when compiled without
      SSL support.  Don't bogusly rewrite such URLs.  */
-  if (p[0] == ':' && p[1] == '/' && p[2] == '/')
+  if (p && p[0] == ':' && p[1] == '/' && p[2] == '/')
     return NULL;
 
-  if (*p == ':')
+  if (p && *p == ':')
     {
-      const char *pp;
-      char *res;
-      /* If the characters after the colon and before the next slash
-	 or end of string are all digits, it's HTTP.  */
-      int digits = 0;
-      for (pp = p + 1; ISDIGIT (*pp); pp++)
-	++digits;
-      if (digits > 0 && (*pp == '/' || *pp == '\0'))
+      /* Colon indicates ftp, as in foo.bar.com:path.  Check for
+	 special case of http port number ("localhost:10000").  */
+      int digits = strspn (p + 1, "0123456789");
+      if (digits && (p[1 + digits] == '/' || p[1 + digits] == '\0'))
 	goto http;
 
-      /* Prepend "ftp://" to the entire URL... */
-      res = xmalloc (6 + strlen (url) + 1);
-      sprintf (res, "ftp://%s", url);
-      /* ...and replace ':' with '/'. */
-      res[6 + (p - url)] = '/';
-      return res;
+      /* Turn "foo.bar.com:path" to "ftp://foo.bar.com/path". */
+      ret = aprintf ("ftp://%s", url);
+      ret[6 + (p - url)] = '/';
     }
   else
     {
-      char *res;
     http:
-      /* Just prepend "http://" to what we have. */
-      res = xmalloc (7 + strlen (url) + 1);
-      sprintf (res, "http://%s", url);
-      return res;
+      /* Just prepend "http://" to URL. */
+      ret = aprintf ("http://%s", url);
     }
+  return ret;
 }
 
 static void split_path (const char *, char **, char **);
