
  func = (merge_with_existing_entries ? hsts_store_merge : hsts_new_entry);

  fp = fopen (file, "r");
  if (fp)
    {
      while (getline (&line, &len, fp) > 0)
        {
          for (p = line; c_isspace (*p); p++)
            ;

          if (*p == '#')
            continue;

          items_read = sscanf (p, "%255s %d %d %lu %lu",
                               host,
                               &port,
                               &include_subdomains,
                               (unsigned long *) &created,
                               (unsigned long *) &max_age);

          if (items_read == 5)
            func (store, host, port, created, max_age, !!include_subdomains);
        }

      xfree (line);
      fclose (fp);

      result = true;
    }

  return result;
}

static void
hsts_store_dump (hsts_store_t store, const char *filename)
{
  FILE *fp = NULL;
  hash_table_iterator it;

  fp = fopen (filename, "w");
  if (fp)
    {
      /* Print preliminary comments. We don't care if any of these fail. */
      fputs ("# HSTS 1.0 Known Hosts database for GNU Wget.\n", fp);
      fputs ("# Edit at your own risk.\n", fp);
      fputs ("# <hostname>[:<port>]\t<incl. subdomains>\t<created>\t<max-age>\n", fp);

      /* Now cycle through the HSTS store in memory and dump the entries */
      for (hash_table_iterate (store->table, &it); hash_table_iter_next (&it);)
        {
          struct hsts_kh *kh = (struct hsts_kh *) it.key;
          struct hsts_kh_info *khi = (struct hsts_kh_info *) it.value;

          if (fprintf (fp, "%s\t%d\t%d\t%lu\t%lu\n",
                       kh->host, kh->explicit_port, khi->include_subdomains,
                       khi->created, khi->max_age) < 0)
            {
              logprintf (LOG_ALWAYS, "Could not write the HSTS database correctly.\n");
              break;
            }
        }

      fclose (fp);
    }
}

