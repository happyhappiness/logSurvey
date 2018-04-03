  
  num_elems = hash_table_count (nonexisting_urls_set);
  assert (num_elems > 0);
  
  if (num_elems > 1) 
    {
      logprintf (LOG_NOTQUIET, _("Found %d broken links.\n\n"), 
                 num_elems);
    }
  else
    {
      logprintf (LOG_NOTQUIET, _("Found 1 broken link.\n\n"));
    }
  
  for (hash_table_iterate (nonexisting_urls_set, &iter);
       hash_table_iter_next (&iter); )
