   /* Fill in the arguments.  */
   for (i = 0; i < nurl; i++, optind++)
     {
-      char *irix4_cc_needs_this;
-      STRDUP_ALLOCA (irix4_cc_needs_this, argv[optind]);
-      url[i] = irix4_cc_needs_this;
+      char *rewritten = rewrite_url_maybe (argv[optind]);
+      if (rewritten)
+	{
+	  printf ("Converted %s to %s\n", argv[optind], rewritten);
+	  url[i] = rewritten;
+	}
+      else
+	url[i] = xstrdup (argv[optind]);
     }
   url[i] = NULL;
 
