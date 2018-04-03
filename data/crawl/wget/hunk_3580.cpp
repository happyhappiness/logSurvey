       mynewloc = construced_newloc;
 
       /* Now, see if this new location makes sense. */
-      newloc_struct = newurl ();
-      newloc_result = parseurl (mynewloc, newloc_struct, 1);
-      if (newloc_result != URLOK)
+      newloc_struct = url_parse (mynewloc, NULL);
+      if (!newloc_struct)
 	{
-	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, uerrmsg (newloc_result));
-	  freeurl (newloc_struct, 1);
-	  freeurl (u, 1);
+	  logprintf (LOG_NOTQUIET, "%s: %s.\n", mynewloc, "UNKNOWN");
+	  url_free (newloc_struct);
+	  url_free (u);
 	  if (redirections)
 	    string_set_free (redirections);
 	  xfree (url);
