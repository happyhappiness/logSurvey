  return stat_info->is_dumpdir;
}

/* Examine the directories under directory_name and delete any
   files that were not there at the time of the back-up. */
void
purge_directory (char const *directory_name)
{
  char *current_dir;
  char *cur, *arc, *p;

  if (!is_dumpdir (&current_stat_info))
    {
      skip_member ();
      return;
    }

  current_dir = savedir (directory_name);

  if (!current_dir)
    {
      /* The directory doesn't exist now.  It'll be created.  In any
	 case, we don't have to delete any files out of it.  */

      skip_member ();
      return;
    }

  /* Process renames */
  for (arc = current_stat_info.dumpdir; *arc; arc += strlen (arc) + 1)
    {
      if (*arc == 'R')
	{
	  char *src, *dst;
	  src = arc + 1;
	  arc += strlen (arc) + 1;
	  dst = arc + 1;

	  if (!rename_directory (src, dst))
	    {
	      free (current_dir);
	      /* FIXME: Make sure purge_directory(dst) will return
		 immediately */
	      return;
	    }
	}
    }
  
  /* Process deletes */
  p = NULL;
