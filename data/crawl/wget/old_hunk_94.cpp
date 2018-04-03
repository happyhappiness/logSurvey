
  if (file_exists_p (filename))
    {
      fp = fopen (filename, "r");

      if (!fp || !hsts_read_database (store, fp, false))
        {
          /* abort! */
          hsts_store_close (store);
          xfree (store);
          goto out;
        }

      if (fstat (fileno (fp), &st) == 0)
        store->last_mtime = st.st_mtime;
    }

out:
  if (fp)
    fclose (fp);

  return store;
}

