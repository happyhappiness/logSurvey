  free (accumulator);
}

/*----------------------------------------------------------------------.
| At the end of an ACCUMULATOR buffer, add a DATA block of SIZE bytes.  |
`----------------------------------------------------------------------*/

static void
add_to_accumulator (struct accumulator *accumulator,
		    const char *data, int size)
{
  if (accumulator->length + size > accumulator->allocated)
    {
      accumulator->allocated = accumulator->length + size + ACCUMULATOR_SLACK;
      accumulator->pointer = (char *)
	xrealloc (accumulator->pointer, (size_t) accumulator->allocated);
    }
  memcpy (accumulator->pointer + accumulator->length, data, (size_t) size);
  accumulator->length += size;
}

/* Incremental dump specialities.  */

/* Current time.  */
static time_t time_now;

/* List of directory names.  */
struct directory
  {
    struct directory *next;	/* next entry in list */
    const char *name;		/* path name of directory */
    int device_number;		/* device number for directory */
    int inode_number;		/* inode number for directory */
    int allnew;
    const char *dir_text;
  };
static struct directory *directory_list = NULL;

/*-------------------------------------------------------------------.
| Create and link a new directory entry for directory NAME, having a |
| DEVICE_NUMBER and a INODE_NUMBER, with some TEXT.		     |
`-------------------------------------------------------------------*/

static void
note_directory (char *name, dev_t device_number, ino_t inode_number,
		const char *text)
{
  struct directory *directory
    = (struct directory *) xmalloc (sizeof (struct directory));

  directory->next = directory_list;
  directory_list = directory;

  directory->device_number = device_number;
  directory->inode_number = inode_number;
  directory->name = xstrdup (name);
  directory->dir_text = text;
  directory->allnew = 0;
}

/*------------------------------------------------------------------------.
| Return a directory entry for a given path NAME, or NULL if none found.  |
`------------------------------------------------------------------------*/

static struct directory *
find_directory (char *name)
{
  struct directory *directory;

  for (directory = directory_list;
       directory;
       directory = directory->next)
    {
      if (!strcmp (directory->name, name))
	return directory;
    }
  return NULL;
}

/*---.
| ?  |
`---*/

static int
compare_dirents (const voidstar first, const voidstar second)
{
  return strcmp ((*(char *const *) first) + 1,
		 (*(char *const *) second) + 1);
}

/*---.
| ?  |
`---*/

char *
get_directory_contents (char *path, int device)
{
  struct accumulator *accumulator;

  /* Recursively scan the given PATH.  */

  {
    DIR *dirp = opendir (path);	/* for scanning directory */
    struct dirent *entry;	/* directory entry being scanned */
    char *name_buffer;		/* directory, `/', and directory member */
    int name_buffer_size;	/* allocated size of name_buffer, minus 2 */
    int name_length;		/* used length in name_buffer */
    struct directory *directory; /* for checking if already already seen */
    int all_children;

    if (dirp == NULL)
      {
	ERROR ((0, errno, _("Cannot open directory %s"), path));
	return NULL;
      }
    errno = 0;			/* FIXME: errno should be read-only */

    name_buffer_size = strlen (path) + NAME_FIELD_SIZE;
    name_buffer = xmalloc ((size_t) (name_buffer_size + 2));
    strcpy (name_buffer, path);
    if (path[strlen (path) - 1] != '/')
      strcat (name_buffer, "/");
    name_length = strlen (name_buffer);

    directory = find_directory (path);
    all_children = directory ? directory->allnew : 0;

    accumulator = new_accumulator ();

    while (entry = readdir (dirp), entry)
      {
	struct stat stat_data;

	/* Skip `.' and `..'.  */

	if (is_dot_or_dotdot (entry->d_name))
	  continue;

	if ((int) NAMLEN (entry) + name_length >= name_buffer_size)
	  {
	    while ((int) NAMLEN (entry) + name_length >= name_buffer_size)
	      name_buffer_size += NAME_FIELD_SIZE;
	    name_buffer = (char *)
	      xrealloc (name_buffer, (size_t) (name_buffer_size + 2));
	  }
	strcpy (name_buffer + name_length, entry->d_name);

	if (dereference_option
#ifdef AIX
	    ? statx (name_buffer, &stat_data, STATSIZE, STX_HIDDEN)
	    : statx (name_buffer, &stat_data, STATSIZE, STX_HIDDEN | STX_LINK)
#else
	    ? stat (name_buffer, &stat_data)
	    : lstat (name_buffer, &stat_data)
#endif
	    )
	  {
	    ERROR ((0, errno, _("Cannot stat %s"), name_buffer));
	    continue;
	  }

	if ((one_file_system_option && device != stat_data.st_dev)
	    || (exclude_option && check_exclude (name_buffer)))
	  add_to_accumulator (accumulator, "N", 1);

#ifdef AIX
	else if (S_ISHIDDEN (stat_data.st_mode))
	  {
	    add_to_accumulator (accumulator, "D", 1);
	    strcat (entry->d_name, "A");
	    entry->d_namlen++;
	  }
#endif

	else if (S_ISDIR (stat_data.st_mode))
	  {
	    if (directory = find_directory (name_buffer), directory)
	      {
		/* Devices having the high bit set are NFS devices, which are
		   attributed somewhat randomly in automounting situations.
		   For avoiding spurious incremental redumping of directories,
		   we have to plainly consider all NFS devices as equal,
		   relying on the i-node only to establish differences.  */

		/* FIXME: Göran Uddeborg <goeran@uddeborg.pp.se> says, on
		   1996-09-20, that SunOS 5/Solaris 2 uses unsigned long for
		   the device number type.  */

		if ((((short) directory->device_number >= 0
		      || (short) stat_data.st_dev >= 0)
		     && directory->device_number != stat_data.st_dev)
		    || directory->inode_number != stat_data.st_ino)
		  {
		    if (verbose_option)
		      WARN ((0, 0, _("Directory %s has been renamed"),
			     name_buffer));
		    directory->allnew = 1;
		    directory->device_number = stat_data.st_dev;
		    directory->inode_number = stat_data.st_ino;
		  }
		directory->dir_text = "";
	      }
	    else
	      {
		if (verbose_option)
		  WARN ((0, 0, _("Directory %s is new"), name_buffer));
		note_directory (name_buffer, stat_data.st_dev, stat_data.st_ino,
				"");
		directory = find_directory (name_buffer);
		directory->allnew = 1;
	      }
	    if (all_children && directory)
	      directory->allnew = 1;

	    add_to_accumulator (accumulator, "D", 1);
	  }

	else
	  if (!all_children
	      && stat_data.st_mtime < newer_mtime_option
	      && (!after_date_option
		  || stat_data.st_ctime < newer_ctime_option))
	    add_to_accumulator (accumulator, "N", 1);
	  else
	    add_to_accumulator (accumulator, "Y", 1);

	add_to_accumulator (accumulator,
			    entry->d_name, (int) (NAMLEN (entry) + 1));
      }
    add_to_accumulator (accumulator, "\000\000", 2);

    free (name_buffer);
    closedir (dirp);
  }

  /* Sort the contents of the directory, now that we have it all.  */
