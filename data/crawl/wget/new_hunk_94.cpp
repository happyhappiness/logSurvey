
  if (file_exists_p (filename))
    {
      if (hsts_file_access_valid (filename))
        {
          struct_stat st;
          FILE *fp = fopen (filename, "r");

          if (!fp || !hsts_read_database (store, fp, false))
            {
              /* abort! */
              hsts_store_close (store);
              xfree (store);
              fclose (fp);
              goto out;
            }

          if (fstat (fileno (fp), &st) == 0)
            store->last_mtime = st.st_mtime;

          fclose (fp);
        }
      else
        {
          /*
           * If we're not reading the HSTS database,
           * then by all means act as if HSTS was disabled.
           */
          hsts_store_close (store);
          xfree (store);

          logprintf (LOG_NOTQUIET, "Will not apply HSTS. "
                     "The HSTS database must be a regular and non-world-writable file.\n");
        }
    }

out:
  return store;
}

