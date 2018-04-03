     {
       if (!chain->permanent)
 	continue;
-      if (chain->expiry_time < cookies_now)
+      if (COOKIE_EXPIRED_P (chain))
 	continue;
-      fprintf (fp, "%s\t%s\t%s\t%s\t%lu\t%s\t%s\n",
-	       domain, *domain == '.' ? "TRUE" : "FALSE",
+      fputs (domain, fp);
+      if (chain->port != PORT_ANY)
+	fprintf (fp, ":%d", chain->port);
+      fprintf (fp, "\t%s\t%s\t%s\t%.0f\t%s\t%s\n",
+	       *domain == '.' ? "TRUE" : "FALSE",
 	       chain->path, chain->secure ? "TRUE" : "FALSE",
-	       chain->expiry_time,
+	       (double)chain->expiry_time,
 	       chain->attr, chain->value);
       if (ferror (fp))
 	return 1;		/* stop mapping */
