      /* ... except if it was explicitely given in the command line */
      && !is_individual_file (name_buffer))
    directory->children = NO_CHILDREN;
  else if (children == ALL_CHILDREN)
    directory->children = ALL_CHILDREN;

  DIR_SET_FLAG (directory, DIRF_INIT);

  {
    const char *tag_file_name;

    switch (check_exclusion_tags (name_buffer, &tag_file_name))
      {
      case exclusion_tag_all:
	/* This warning can be duplicated by code in dump_file0, but only
	   in case when the topmost directory being archived contains
	   an exclusion tag. */
	exclusion_tag_warning (name_buffer, tag_file_name,
			       _("directory not dumped"));
	if (entry)
	  *entry = 'N';
	directory->children = NO_CHILDREN;
	break;

      case exclusion_tag_contents:
	exclusion_tag_warning (name_buffer, tag_file_name,
			       _("contents not dumped"));
	directory->children = NO_CHILDREN;
	break;

      case exclusion_tag_under:
	exclusion_tag_warning (name_buffer, tag_file_name,
			       _("contents not dumped"));
	directory->tagfile = tag_file_name;
	break;

      case exclusion_tag_none:
	break;
      }
  }

  return directory;
}
