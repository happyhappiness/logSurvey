 {
   FILE *fp = (FILE *)arg;
   char *domain = (char *)key;
-  struct cookie *chain = (struct cookie *)value;
-  for (; chain; chain = chain->next)
+  struct cookie *cookie = (struct cookie *)value;
+  for (; cookie; cookie = cookie->next)
     {
-      if (!chain->permanent)
+      if (!cookie->permanent)
 	continue;
-      if (COOKIE_EXPIRED_P (chain))
+      if (COOKIE_EXPIRED_P (cookie))
 	continue;
+      if (!cookie->domain_exact)
+	fputc ('.', fp);
       fputs (domain, fp);
-      if (chain->port != PORT_ANY)
-	fprintf (fp, ":%d", chain->port);
+      if (cookie->port != PORT_ANY)
+	fprintf (fp, ":%d", cookie->port);
       fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
-	       *domain == '.' ? "TRUE" : "FALSE",
-	       chain->path, chain->secure ? "TRUE" : "FALSE",
-	       (double)chain->expiry_time,
-	       chain->attr, chain->value);
+	       cookie->domain_exact ? "FALSE" : "TRUE",
+	       cookie->path, cookie->secure ? "TRUE" : "FALSE",
+	       (double)cookie->expiry_time,
+	       cookie->attr, cookie->value);
       if (ferror (fp))
 	return 1;		/* stop mapping */
     }
