 {
   hash_table_iterator iter;
   int num_elems;
-  
-  if (!nonexisting_urls_set) 
+
+  if (!nonexisting_urls_set)
     {
       logprintf (LOG_NOTQUIET, _("Found no broken links.\n\n"));
       return;
     }
-  
+
   num_elems = hash_table_count (nonexisting_urls_set);
   assert (num_elems > 0);
 
   logprintf (LOG_NOTQUIET, ngettext("Found %d broken link.\n\n",
                                     "Found %d broken links.\n\n", num_elems),
              num_elems);
-  
+
   for (hash_table_iterate (nonexisting_urls_set, &iter);
        hash_table_iter_next (&iter); )
     {
       /* Struct url_list *list; */
       const char *url = (const char *) iter.key;
-          
+
       logprintf (LOG_NOTQUIET, _("%s\n"), url);
     }
   logputs (LOG_NOTQUIET, "\n");
