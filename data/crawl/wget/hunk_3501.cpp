 	  string_set_add (redirections, u->url);
 	}
 
-      /* The new location is OK.  Check for redirection cycle by
+      /* The new location is OK.  Check for max. number of
+	 redirections.  */
+      if (++redirection_count > MAX_REDIRECTIONS)
+	{
+	  logprintf (LOG_NOTQUIET, _("%d redirections exceeded.\n"),
+		     MAX_REDIRECTIONS);
+	  url_free (newloc_parsed);
+	  url_free (u);
+	  if (redirections)
+	    string_set_free (redirections);
+	  xfree (url);
+	  xfree (mynewloc);
+	  return WRONGCODE;
+	}
+
+      /*Check for redirection cycle by
          peeking through the history of redirections. */
       if (string_set_contains (redirections, newloc_parsed->url))
 	{
