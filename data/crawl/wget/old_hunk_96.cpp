  /* Print preliminary comments. We don't care if any of these fail. */
  fputs ("# HSTS 1.0 Known Hosts database for GNU Wget.\n", fp);
  fputs ("# Edit at your own risk.\n", fp);
  fputs ("# <hostname>[:<port>]\t<incl. subdomains>\t<created>\t<max-age>\n", fp);

  /* Now cycle through the HSTS store in memory and dump the entries */
  for (hash_table_iterate (store->table, &it); hash_table_iter_next (&it);)
