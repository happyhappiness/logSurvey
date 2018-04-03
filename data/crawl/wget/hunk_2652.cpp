     }
 }
 
+/* Remembers broken links.  */
+
+struct broken_urls_list 
+{
+  char *url;
+  struct broken_urls_list *next;
+};
+
+static bool
+in_list (const struct broken_urls_list *list, const char *url)
+{
+  const struct broken_urls_list *ptr;
+  
+  for (ptr = list; ptr; ptr = ptr->next)
+    {
+      /* TODO: strcasecmp may not be appropriate to compare URLs */
+      if (strcasecmp (url, ptr->url) == 0) return true;      
+    }
+  
+  return false;
+}
+
+void
+nonexisting_url (const char *url, const char *referrer)
+{
+  struct broken_urls_list *list;
+  
+  if (!nonexisting_urls_hash)
+    nonexisting_urls_hash = make_string_hash_table (0);
+
+  list = hash_table_get (nonexisting_urls_hash, url);
+  if (!list)
+    {
+      list = (struct broken_urls_list *) xnew0 (struct broken_urls_list);
+      list->url = referrer ? xstrdup (referrer) : NULL;
+      hash_table_put (nonexisting_urls_hash, xstrdup (url), list);
+    }
+  else if (list && !in_list (list, referrer)) 
+    {
+      /* Append referrer at the end of the list */
+      struct broken_urls_list *newnode;
+      
+      while (list->next) list = list->next;
+      
+      newnode = xnew0 (struct broken_urls_list);
+      newnode->url = xstrdup (referrer);
+      list->next = newnode;
+    }
+}
+
+static void
+nonexisting_urls_free (void)
+{
+  if (nonexisting_urls_hash)
+    {
+      hash_table_iterator iter;
+      for (hash_table_iterate (nonexisting_urls_hash, &iter);
+	   hash_table_iter_next (&iter);
+	   )
+        {
+	  xfree (iter.key);
+	  xfree (iter.value);
+	}
+      hash_table_destroy (nonexisting_urls_hash);
+      nonexisting_urls_hash = NULL;
+    }
+}
+
+void
+print_broken_links (void)
+{
+  hash_table_iterator iter;
+  int num_elems;
+  
+  if (!nonexisting_urls_hash) 
+    {
+      logprintf (LOG_NOTQUIET, _("Found no broken links.\n\n"));
+      return;
+    }
+  
+  num_elems = hash_table_count (nonexisting_urls_hash);
+  assert (num_elems > 0);
+  
+  if (num_elems > 1) 
+    {
+      logprintf (LOG_NOTQUIET, _("Found %d broken links.\n\n"), 
+                 num_elems);
+    }
+  else
+    {
+      logprintf (LOG_NOTQUIET, _("Found 1 broken link.\n\n"));
+    }
+  
+  for (hash_table_iterate (nonexisting_urls_hash, &iter);
+       hash_table_iter_next (&iter);
+       )
+    {
+      struct broken_urls_list *list;
+	  
+      logprintf (LOG_NOTQUIET, _("%s referred by:\n"), (const char *)iter.key);
+
+      for (list = (struct broken_urls_list *) iter.value; 
+           list; 
+	   list = list->next) 
+        {
+          logprintf (LOG_NOTQUIET, _("    %s\n"), list->url);
+        }
+    }
+  logputs (LOG_NOTQUIET, "\n");
+}
+
+
 /* The function returns the pointer to the malloc-ed quoted version of
    string s.  It will recognize and quote numeric and special graphic
    entities, as per RFC1866:
