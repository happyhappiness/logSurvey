       )
    {
      struct broken_urls_list *list;
          
      logprintf (LOG_NOTQUIET, _("%s referred by:\n"), (const char *)iter.key);

      for (list = (struct broken_urls_list *) iter.value; 
           list; 
           list = list->next) 
        {
          logprintf (LOG_NOTQUIET, _("    %s\n"), list->url);
        }
