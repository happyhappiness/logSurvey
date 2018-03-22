  struct file_id_list *next;
  ino_t ino;
  dev_t dev;
};

static struct file_id_list *file_id_list;

static int
add_file_id (const char *filename)
{
  struct file_id_list *p;
  struct stat st;

  if (stat (filename, &st))
    stat_fatal (filename);
  for (p = file_id_list; p; p = p->next)
    if (p->ino == st.st_ino && p->dev == st.st_dev)
      {
	ERROR ((0, 0, _("%s: file list already read"),
		quotearg_colon (filename)));
	return 1;
      }
  p = xmalloc (sizeof *p);
  p->next = file_id_list;
  p->ino = st.st_ino;
  p->dev = st.st_dev;
  file_id_list = p;
  return 0;
}
