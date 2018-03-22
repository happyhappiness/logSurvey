	WARN ((0, 0,
	       _("%s: file is on a different filesystem; not dumped"),
	       quotearg_colon (st->orig_file_name)));
      return;
    }
  
  {
    char const *entry;
    size_t entry_len;
    char *name_buf = xstrdup (st->orig_file_name);
    size_t name_size = strlen (name_buf);
    size_t name_len = name_size;

    /* Now output all the files in the directory.  */
    /* FIXME: Should speed this up by cd-ing into the dir.  */

    for (entry = directory; (entry_len = strlen (entry)) != 0;
	 entry += entry_len + 1)
      {
	if (name_size < name_len + entry_len)
	  {
	    name_size = name_len + entry_len;
	    name_buf = xrealloc (name_buf, name_size + 1);
	  }
	strcpy (name_buf + name_len, entry);
	if (!excluded_name (name_buf))
	  dump_file (name_buf, 0, our_device);
      }

    free (name_buf);
  }
}

/* Ensure exactly one trailing slash.  */
