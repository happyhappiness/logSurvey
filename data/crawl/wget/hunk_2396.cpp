       struct url_list *list;
       const char *url = (const char *) iter.key;
           
-      logprintf (LOG_NOTQUIET, _("%s referred by:\n"), url);
-      
-      for (list = (struct url_list *) hash_table_get (visited_urls_hash, url); 
-           list; list = list->next) 
-        {
-          logprintf (LOG_NOTQUIET, _("    %s\n"), list->url);
-        }
+      logprintf (LOG_NOTQUIET, _("%s\n"), url);
     }
   logputs (LOG_NOTQUIET, "\n");
 }
