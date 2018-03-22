
/* Restoration of incremental dumps.  */

void
get_gnu_dumpdir ()
{
  size_t size;
  size_t copied;
  union block *data_block;
  char *to;
  char *archive_dir;
  
  size = current_stat_info.stat.st_size;
  if (size != current_stat_info.stat.st_size)
    xalloc_die ();

  archive_dir = xmalloc (size);
  to = archive_dir;

  set_next_block_after (current_header);
  if (multi_volume_option)
    {
      assign_string (&save_name, current_stat_info.orig_file_name);
      save_totsize = current_stat_info.stat.st_size;
    }
  for (; size > 0; size -= copied)
    {
      if (multi_volume_option)
	save_sizeleft = size;
      data_block = find_next_block ();
      if (!data_block)
	ERROR ((1, 0, _("Unexpected EOF in archive")));
      copied = available_space_after (data_block);
      if (copied > size)
	copied = size;
