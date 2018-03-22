
/* Restoration of incremental dumps.  */

/* Examine the directories under directory_name and delete any
   files that were not there at the time of the back-up. */
void
purge_directory (char const *directory_name)
{
  char *archive_dir;
  char *current_dir;
  char *cur, *arc;
  size_t size;
  size_t copied;
  union block *data_block;
  char *to;

  current_dir = savedir (directory_name);

  if (!current_dir)
    {
      /* The directory doesn't exist now.  It'll be created.  In any
	 case, we don't have to delete any files out of it.  */

      skip_member ();
      return;
    }

  size = current_stat_info.stat.st_size;
  if (size != current_stat_info.stat.st_size)
    xalloc_die ();
  archive_dir = xmalloc (size);
  to = archive_dir;
  for (; size > 0; size -= copied)
    {
      data_block = find_next_block ();
      if (!data_block)
	{
	  ERROR ((0, 0, _("Unexpected EOF in archive")));
	  break;		/* FIXME: What happens then?  */
	}
      copied = available_space_after (data_block);
      if (copied > size)
	copied = size;
