    return buffer;
  }
}

/*----------------------------------------------------------------------.
| Add all the files in PATH, which is a directory, to the namelist.  If |
| any of the files is a directory, recurse on the subdirectory.	        |
`----------------------------------------------------------------------*/

static void
add_hierarchy_to_namelist (char *path, int device)
{
  char *buffer = get_directory_contents (path, device);

  {
    struct name *name;

    for (name = namelist; name; name = name->next)
      if (strcmp (name->name, path) == 0)
	  break;
    if (name)
      name->dir_contents = buffer ? buffer : "\0\0\0\0";
  }

  if (buffer)
    {
      int name_length = strlen (path);
      int allocated_length = (name_length >= NAME_FIELD_SIZE
			      ? name_length + NAME_FIELD_SIZE
			      : NAME_FIELD_SIZE);
      char *name_buffer = xmalloc ((size_t) (allocated_length + 1));
				/* FIXME: + 2 above?  */
      char *string;
      int string_length;

      strcpy (name_buffer, path);
      if (name_buffer[name_length - 1] != '/')
	{
	  name_buffer[name_length++] = '/';
	  name_buffer[name_length] = '\0';
	}

      for (string = buffer; *string; string += string_length + 1)
	{
	  string_length = strlen (string);
	  if (*string == 'D')
	    {
	      if (name_length + string_length >= allocated_length)
		{
		  while (name_length + string_length >= allocated_length)
		    allocated_length += NAME_FIELD_SIZE;
		  name_buffer = (char *)
		    xrealloc (name_buffer, (size_t) (allocated_length + 1));
		}
	      strcpy (name_buffer + name_length, string + 1);
	      addname (name_buffer);
	      add_hierarchy_to_namelist (name_buffer, device);
	    }
	}

      free (name_buffer);
    }
}

/*---.
| ?  |
`---*/

static void
read_directory_file (void)
{
  dev_t device_number;
  ino_t inode_number;
  char *strp;
  FILE *fp;
  char buf[512];
  static char *path = NULL;

  if (path == NULL)
    path = xmalloc (PATH_MAX);
  time (&time_now);
  if (listed_incremental_option[0] != '/')
    {
#if HAVE_GETCWD
      if (!getcwd (path, PATH_MAX))
	FATAL_ERROR ((0, 0, _("Could not get current directory")));
#else
      char *getwd ();

      if (!getwd (path))
	FATAL_ERROR ((0, 0, _("Could not get current directory: %s"), path));
#endif

      if (strlen (path) + 1 + strlen (listed_incremental_option) + 1 > PATH_MAX)
	ERROR ((TAREXIT_FAILURE, 0, _("File name %s/%s too long"),
		path, listed_incremental_option));

      strcat (path, "/");
      strcat (path, listed_incremental_option);
      listed_incremental_option = path;
    }
  fp = fopen (listed_incremental_option, "r");
  if (fp == 0 && errno != ENOENT)
    {
      ERROR ((0, errno, _("Cannot open %s"), listed_incremental_option));
      return;
    }
  if (!fp)
    return;
  fgets (buf, sizeof (buf), fp);

  /* FIXME: Using after_date_option as a first time flag looks fairly
     dubious to me!  So, using -N with incremental might be buggy just
     because of the next few lines.  I saw a few unexplained, almost harsh
     advices, from other GNU people, about *not* using -N with incremental
     dumps, and here might lie (part of) the reason.  */
  if (!after_date_option)
    {
      newer_mtime_option = atol (buf);
      after_date_option = 1;
    }

  while (fgets (buf, sizeof (buf), fp))
    {
      strp = &buf[strlen (buf)];
      if (strp[-1] == '\n')
	strp[-1] = '\0';
      /* FIXME: For files ending with an incomplete line, maybe a NUL might
	 be missing, here...  */

      strp = buf;
      device_number = atol (strp);
      while (ISDIGIT (*strp))
	strp++;
      inode_number = atol (strp);
      while (ISSPACE (*strp))
	strp++;
      while (ISDIGIT (*strp))
	strp++;
      strp++;
      unquote_string (strp);
      note_directory (strp, device_number, inode_number, NULL);
    }
  if (fclose (fp) == EOF)
    ERROR ((0, errno, "%s", listed_incremental_option));
}

/*---.
| ?  |
`---*/

void
write_dir_file (void)
{
  FILE *fp;
  struct directory *directory;
  char *str;

  fp = fopen (listed_incremental_option, "w");
  if (fp == 0)
    {
      ERROR ((0, errno, _("Cannot write to %s"), listed_incremental_option));
      return;
    }
  fprintf (fp, "%lu\n", time_now);
  for (directory = directory_list; directory; directory = directory->next)
    {
      if (!directory->dir_text)
	continue;
      str = quote_copy_string (directory->name);
      if (str)
	{
	  fprintf (fp, "%u %u %s\n", directory->device_number,
		   directory->inode_number, str);
	  free (str);
	}
      else
	fprintf (fp, "%u %u %s\n", directory->device_number,
		 directory->inode_number, directory->name);
    }
  if (fclose (fp) == EOF)
    ERROR ((0, errno, "%s", listed_incremental_option));
}

/*---.
| ?  |
`---*/

static int
compare_names (char *param1, char *param2)
{
  struct name *n1 = (struct name *) param1;
  struct name *n2 = (struct name *) param2;

  if (n1->found)
    return n2->found ? strcmp (n1->name, n2->name) : -1;

  if (n2->found)
    return 1;

  return strcmp (n1->name, n2->name);
}

/*-------------------------------------------------------------------------.
| Collect all the names from argv[] (or whatever), then expand them into a |
| directory tree, and put all the directories at the beginning.		   |
`-------------------------------------------------------------------------*/

void
collect_and_sort_names (void)
{
  struct name *name;
  struct name *next_name;
  int num_names;
  struct stat statbuf;

  name_gather ();

  if (listed_incremental_option)
    read_directory_file ();

  if (!namelist)
    addname (".");

  for (name = namelist; name; name = next_name)
    {
      next_name = name->next;
      if (name->found || name->dir_contents)
	continue;
      if (name->regexp)		/* FIXME: just skip regexps for now */
	continue;
      if (name->change_dir)
	if (chdir (name->change_dir) < 0)
	  {
	    ERROR ((0, errno, _("Cannot chdir to %s"), name->change_dir));
	    continue;
	  }

      if (
#ifdef AIX
	  statx (name->name, &statbuf, STATSIZE, STX_HIDDEN | STX_LINK)
#else
	  lstat (name->name, &statbuf) < 0
#endif
	  )
	{
	  ERROR ((0, errno, _("Cannot stat %s"), name->name));
	  continue;
	}
      if (S_ISDIR (statbuf.st_mode))
	{
	  name->found = 1;
	  add_hierarchy_to_namelist (name->name, statbuf.st_dev);
	}
    }

  num_names = 0;
  for (name = namelist; name; name = name->next)
    num_names++;
  namelist = (struct name *)
    merge_sort ((voidstar) namelist, num_names,
		(char *) (&(namelist->next)) - (char *) namelist,
		compare_names);

  for (name = namelist; name; name = name->next)
    name->found = 0;

  if (listed_incremental_option)
    write_dir_file ();
}

/* Restoration of incremental dumps.  */

/*---.
| ?  |
`---*/

void
gnu_restore (int skipcrud)
{
  char *current_dir;
  char *archive_dir;
  struct accumulator *accumulator;
  char *p;
  DIR *dirp;
  struct dirent *d;
  char *cur, *arc;
  long size, copied;
  union block *data_block;
  char *to;

#define CURRENT_FILE_NAME (skipcrud + current_file_name)

  dirp = opendir (CURRENT_FILE_NAME);

  if (!dirp)
    {
      /* The directory doesn't exist now.  It'll be created.  In any
	 case, we don't have to delete any files out of it.  */

      skip_file ((long) current_stat.st_size);
      return;
    }

  accumulator = new_accumulator ();
  while (d = readdir (dirp), d)
    {
      if (is_dot_or_dotdot (d->d_name))
	continue;

      add_to_accumulator (accumulator, d->d_name, (int) (NAMLEN (d) + 1));
    }
  closedir (dirp);
  add_to_accumulator (accumulator, "", 1);

  current_dir = get_accumulator (accumulator);
  archive_dir = (char *) xmalloc ((size_t) current_stat.st_size);
  to = archive_dir;
  for (size = current_stat.st_size; size > 0; size -= copied)
    {
      data_block = find_next_block ();
      if (!data_block)
