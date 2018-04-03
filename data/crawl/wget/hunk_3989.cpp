   location_changed = (result == NEWLOCATION);
   if (location_changed)
     {
-      if (mynewloc)
+      char *construced_newloc;
+      uerr_t newloc_result;
+      struct urlinfo *newloc_struct;
+
+      assert (mynewloc != NULL);
+
+      /* The HTTP specs only allow absolute URLs to appear in
+	 redirects, but a ton of boneheaded webservers and CGIs out
+	 there break the rules and use relative URLs, and popular
+	 browsers are lenient about this, so wget should be too. */
+      construced_newloc = url_concat (url, mynewloc);
+      free (mynewloc);
+      mynewloc = construced_newloc;
+
+      /* Now, see if this new location makes sense. */
+      newloc_struct = newurl ();
+      newloc_result = parseurl (mynewloc, newloc_struct, 1);
+      if (newloc_result != URLOK)
 	{
-	  /* The HTTP specs only allow absolute URLs to appear in
-	     redirects, but a ton of boneheaded webservers and CGIs
-	     out there break the rules and use relative URLs, and
-	     popular browsers are lenient about this, so wget should
-	     be too. */
-	  char *construced_newloc = url_concat (url, mynewloc);
-	  free (mynewloc);
-	  mynewloc = construced_newloc;
+	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, uerrmsg (newloc_result));
+	  freeurl (newloc_struct, 1);
+	  freeurl (u, 1);
+	  free_slist (redirections);
+	  return result;
 	}
+
+      /* Now mynewloc will become newloc_struct->url, because if the
+         Location contained relative paths like .././something, we
+         don't want that propagating as url.  */
+      free (mynewloc);
+      mynewloc = xstrdup (newloc_struct->url);
+
       /* Check for redirection to back to itself.  */
-      if (url_equal (url, mynewloc))
+      if (!strcmp (u->url, newloc_struct->url))
 	{
 	  logprintf (LOG_NOTQUIET, _("%s: Redirection to itself.\n"),
 		     mynewloc);
+	  freeurl (newloc_struct, 1);
+	  freeurl (u, 1);
+	  free_slist (redirections);
+	  return WRONGCODE;
+	}
+
+      /* The new location is OK.  Let's check for redirection cycle by
+         peeking through the history of redirections. */
+      if (in_slist (redirections, newloc_struct->url))
+	{
+	  logprintf (LOG_NOTQUIET, _("%s: Redirection cycle detected.\n"),
+		     mynewloc);
+	  freeurl (newloc_struct, 1);
+	  freeurl (u, 1);
+	  free_slist (redirections);
 	  return WRONGCODE;
 	}
+
+      redirections = add_slist (redirections, newloc_struct->url, NOSORT);
+
       free (url);
       url = mynewloc;
       freeurl (u, 1);
-      already_redirected = 1;
-      goto again;
+      u = newloc_struct;
+      goto redirected;
     }
+
   if (file)
     {
       if (u->local)
