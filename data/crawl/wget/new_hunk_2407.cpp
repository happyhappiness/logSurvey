  
  num_elems = hash_table_count (nonexisting_urls_set);
  assert (num_elems > 0);

  logprintf (LOG_NOTQUIET, ngettext("Found %d broken link.\n\n",
                                    "Found %d broken links.\n\n", num_elems),
             num_elems);
  
  for (hash_table_iterate (nonexisting_urls_set, &iter);
       hash_table_iter_next (&iter); )
