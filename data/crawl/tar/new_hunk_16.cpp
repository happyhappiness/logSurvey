  struct file_id_list *next;
  ino_t ino;
  dev_t dev;
  const char *from_file;
};

static struct file_id_list *file_id_list;

/* Return the name of the file from which the file names and options
   are being read.
*/
static const char *
file_list_name ()
{
  struct name_elt *elt;

  for (elt = name_head; elt; elt = elt->next)
    if (elt->type == NELT_FILE && elt->v.file.fp)
      return elt->v.file.name;
  return _("command line");
}

static int
add_file_id (const char *filename)
{
  struct file_id_list *p;
  struct stat st;
  const char *reading_from;

  if (stat (filename, &st))
    stat_fatal (filename);
  reading_from = file_list_name ();
  for (p = file_id_list; p; p = p->next)
    if (p->ino == st.st_ino && p->dev == st.st_dev)
      {
	int oldc = set_char_quoting (NULL, ':', 1);
	ERROR ((0, 0,
		_("%s: file list requested from %s already read from %s"),
		quotearg_n (0, filename),
		reading_from, p->from_file));
	set_char_quoting (NULL, ':', oldc);
	return 1;
      }
  p = xmalloc (sizeof *p);
  p->next = file_id_list;
  p->ino = st.st_ino;
  p->dev = st.st_dev;
  p->from_file = reading_from;
  file_id_list = p;
  return 0;
}
