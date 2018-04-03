 	  string_set_add (redirections, u->url);
 	}
 
-      /* The new location is OK.  Let's check for redirection cycle by
+      /* The new location is OK.  Check for redirection cycle by
          peeking through the history of redirections. */
       if (string_set_contains (redirections, newloc_struct->url))
 	{
 	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
 		     mynewloc);
-	  freeurl (newloc_struct, 1);
-	  freeurl (u, 1);
+	  url_free (newloc_struct);
+	  url_free (u);
 	  if (redirections)
 	    string_set_free (redirections);
 	  xfree (url);
