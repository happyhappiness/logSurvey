       free (mynewloc);
       mynewloc = xstrdup (newloc_struct->url);
 
-      /* Check for redirection to back to itself.  */
-      if (!strcmp (u->url, newloc_struct->url))
+      if (!redirections)
 	{
-	  logprintf (LOG_NOTQUIET, _("%s: Redirection to itself.\n"),
-		     mynewloc);
-	  freeurl (newloc_struct, 1);
-	  freeurl (u, 1);
-	  free_slist (redirections);
-	  free (url);
-	  free (mynewloc);
-	  return WRONGCODE;
+	  redirections = make_string_hash_table (0);
+	  /* Add current URL immediately so we can detect it as soon
+             as possible in case of a cycle. */
+	  string_set_add (redirections, u->url);
 	}
 
       /* The new location is OK.  Let's check for redirection cycle by
          peeking through the history of redirections. */
-      if (in_slist (redirections, newloc_struct->url))
+      if (string_set_exists (redirections, newloc_struct->url))
 	{
 	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
 		     mynewloc);
 	  freeurl (newloc_struct, 1);
 	  freeurl (u, 1);
-	  free_slist (redirections);
+	  if (redirections)
+	    string_set_free (redirections);
 	  free (url);
 	  free (mynewloc);
 	  return WRONGCODE;
 	}
-
-      redirections = add_slist (redirections, newloc_struct->url, NOSORT);
+      string_set_add (redirections, newloc_struct->url);
 
       free (url);
       url = mynewloc;
