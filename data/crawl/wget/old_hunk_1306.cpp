  for (hash_table_iterate (nonexisting_urls_set, &iter);
       hash_table_iter_next (&iter); )
    {
      struct url_list *list;
      const char *url = (const char *) iter.key;
          
      logprintf (LOG_NOTQUIET, _("%s\n"), url);
