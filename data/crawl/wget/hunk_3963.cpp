     {
       logprintf (LOG_NOTQUIET, "%s: %s.\n", url, uerrmsg (result));
       freeurl (u, 1);
-      free_slist (redirections);
+      if (redirections)
+	string_set_free (redirections);
       free (url);
       return result;
     }
