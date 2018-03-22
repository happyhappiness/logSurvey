	WARN ((0, 0,
	       _("%s: file is on a different filesystem; not dumped"),
	       quotearg_colon (st->orig_file_name)));
    }
  else
    {
      char *name_buf;
      size_t name_size;
      
      switch (check_exclusion_tags (st->orig_file_name, &tag_file_name))
	{
	case exclusion_tag_none:
	case exclusion_tag_all:
	  {
	    char const *entry;
	    size_t entry_len;
	    size_t name_len;

	    name_buf = xstrdup (st->orig_file_name);
	    name_size = name_len = strlen (name_buf);

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
	  break;

	case exclusion_tag_contents:
	  exclusion_tag_warning (st->orig_file_name, tag_file_name,
				 _("contents not dumped"));
	  name_size = strlen (st->orig_file_name) + strlen (tag_file_name) + 1;
	  name_buf = xmalloc (name_size);
	  strcpy (name_buf, st->orig_file_name);
	  strcat (name_buf, tag_file_name);
	  dump_file (name_buf, 0, our_device);
	  free (name_buf);
	  break;
      
	case exclusion_tag_under:
	  exclusion_tag_warning (st->orig_file_name, tag_file_name,
				 _("contents not dumped"));
	  break;
	}
    }
}

/* Ensure exactly one trailing slash.  */
