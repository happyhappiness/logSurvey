  free (accumulator);
}

/* At the end of an ACCUMULATOR buffer, add a DATA block of SIZE bytes.  */
static void
add_to_accumulator (struct accumulator *accumulator,
		    const char *data, size_t size)
{
  if (accumulator->length + size > accumulator->allocated)
    {
      accumulator->allocated = accumulator->length + size + ACCUMULATOR_SLACK;
      accumulator->pointer =
	xrealloc (accumulator->pointer, accumulator->allocated);
    }
  memcpy (accumulator->pointer + accumulator->length, data, size);
  accumulator->length += size;
}

/* Incremental dump specialities.  */

/* Which child files to save under a directory.  */
enum children {NO_CHILDREN, CHANGED_CHILDREN, ALL_CHILDREN};

/* Directory attributes.  */
struct directory
  {
    dev_t device_number;	/* device number for directory */
    ino_t inode_number;		/* inode number for directory */
    enum children children;
    bool nfs;
    bool found;
    char name[1];		/* path name of directory */
  };

static Hash_table *directory_table;

#if HAVE_ST_FSTYPE_STRING
  static char const nfs_string[] = "nfs";
# define NFS_FILE_STAT(st) (strcmp ((st).st_fstype, nfs_string) == 0)
#else
# define ST_DEV_MSB(st) (~ (dev_t) 0 << (sizeof (st).st_dev * CHAR_BIT - 1))
# define NFS_FILE_STAT(st) (((st).st_dev & ST_DEV_MSB (st)) != 0)
#endif

/* Calculate the hash of a directory.  */
static unsigned
hash_directory (void const *entry, unsigned n_buckets)
{
  struct directory const *directory = entry;
  return hash_string (directory->name, n_buckets);
}

/* Compare two directories for equality.  */
static bool
compare_directories (void const *entry1, void const *entry2)
{
  struct directory const *directory1 = entry1;
  struct directory const *directory2 = entry2;
  return strcmp (directory1->name, directory2->name) == 0;
}

/* Create and link a new directory entry for directory NAME, having a
   device number DEV and an inode number INO, with NFS indicating
   whether it is an NFS device and FOUND indicating whether we have
   found that the directory exists.  */
static struct directory *
note_directory (char const *name, dev_t dev, ino_t ino, bool nfs, bool found)
{
  size_t size = offsetof (struct directory, name) + strlen (name) + 1;
  struct directory *directory = xmalloc (size);

  directory->device_number = dev;
  directory->inode_number = ino;
  directory->children = CHANGED_CHILDREN;
  directory->nfs = nfs;
  directory->found = found;
  strcpy (directory->name, name);

  if (! ((directory_table
	  || (directory_table = hash_initialize (0, 0, hash_directory,
						 compare_directories, 0)))
	 && hash_insert (directory_table, directory)))
    xalloc_die ();

  return directory;
}

/* Return a directory entry for a given path NAME, or zero if none found.  */
static struct directory *
find_directory (char *name)
{
  if (! directory_table)
    return 0;
  else
    {
      size_t size = offsetof (struct directory, name) + strlen (name) + 1;
      struct directory *dir = alloca (size);
      strcpy (dir->name, name);
      return hash_lookup (directory_table, dir);
    }
}

static int
compare_dirents (const void *first, const void *second)
{
  return strcmp ((*(char *const *) first) + 1,
		 (*(char *const *) second) + 1);
}

char *
get_directory_contents (char *path, dev_t device)
{
  struct accumulator *accumulator;

  /* Recursively scan the given PATH.  */

  {
    char *dirp = savedir (path);	/* for scanning directory */
    char const *entry;	/* directory entry being scanned */
    size_t entrylen;	/* length of directory entry */
    char *name_buffer;		/* directory, `/', and directory member */
    size_t name_buffer_size;	/* allocated size of name_buffer, minus 2 */
    size_t name_length;		/* used length in name_buffer */
    struct directory *directory; /* for checking if already already seen */
    enum children children;

    if (! dirp)
      {
	if (ignore_failed_read_option)
	  savedir_warn (path);
	else
	  savedir_error (path);
      }
    errno = 0;

    name_buffer_size = strlen (path) + NAME_FIELD_SIZE;
    name_buffer = xmalloc (name_buffer_size + 2);
    strcpy (name_buffer, path);
    if (! ISSLASH (path[strlen (path) - 1]))
      strcat (name_buffer, "/");
    name_length = strlen (name_buffer);

    directory = find_directory (path);
    children = directory ? directory->children : CHANGED_CHILDREN;

    accumulator = new_accumulator ();

    if (dirp && children != NO_CHILDREN)
      for (entry = dirp;
	   (entrylen = strlen (entry)) != 0;
	   entry += entrylen + 1)
	{
	  if (name_buffer_size <= entrylen + name_length)
	    {
	      do
		name_buffer_size += NAME_FIELD_SIZE;
	      while (name_buffer_size <= entrylen + name_length);
	      name_buffer = xrealloc (name_buffer, name_buffer_size + 2);
	    }
	  strcpy (name_buffer + name_length, entry);

	  if (excluded_name (name_buffer))
	    add_to_accumulator (accumulator, "N", 1);
	  else
	    {
	      struct stat stat_data;

	      if (deref_stat (dereference_option, name_buffer, &stat_data))
		{
		  if (ignore_failed_read_option)
		    stat_warn (name_buffer);
		  else
		    stat_error (name_buffer);
		  continue;
		}

	      if (S_ISDIR (stat_data.st_mode))
		{
		  bool nfs = NFS_FILE_STAT (stat_data);

		  if (directory = find_directory (name_buffer), directory)
		    {
		      /* With NFS, the same file can have two different devices
			 if an NFS directory is mounted in multiple locations,
			 which is relatively common when automounting.
			 To avoid spurious incremental redumping of
			 directories, consider all NFS devices as equal,
			 relying on the i-node to establish differences.  */

		      if (! (((directory->nfs & nfs)
			      || directory->device_number == stat_data.st_dev)
			     && directory->inode_number == stat_data.st_ino))
			{
			  if (verbose_option)
			    WARN ((0, 0, _("%s: Directory has been renamed"),
				   quotearg_colon (name_buffer)));
			  directory->children = ALL_CHILDREN;
			  directory->nfs = nfs;
			  directory->device_number = stat_data.st_dev;
			  directory->inode_number = stat_data.st_ino;
			}
		      directory->found = 1;
		    }
		  else
		    {
		      if (verbose_option)
			WARN ((0, 0, _("%s: Directory is new"),
			       quotearg_colon (name_buffer)));
		      directory = note_directory (name_buffer,
						  stat_data.st_dev,
						  stat_data.st_ino, nfs, 1);
		      directory->children =
			((listed_incremental_option
			  || newer_mtime_option <= stat_data.st_mtime
			  || (after_date_option &&
			      newer_ctime_option <= stat_data.st_ctime))
			 ? ALL_CHILDREN
			 : CHANGED_CHILDREN);
		    }

		  if (one_file_system_option && device != stat_data.st_dev)
		    directory->children = NO_CHILDREN;
		  else if (children == ALL_CHILDREN)
		    directory->children = ALL_CHILDREN;

		  add_to_accumulator (accumulator, "D", 1);
		}

	      else if (one_file_system_option && device != stat_data.st_dev)
		add_to_accumulator (accumulator, "N", 1);

#ifdef S_ISHIDDEN
	      else if (S_ISHIDDEN (stat_data.st_mode))
		{
		  add_to_accumulator (accumulator, "D", 1);
		  add_to_accumulator (accumulator, entry, entrylen);
		  add_to_accumulator (accumulator, "A", 2);
		  continue;
		}
#endif

	      else
		if (children == CHANGED_CHILDREN
		    && stat_data.st_mtime < newer_mtime_option
		    && (!after_date_option
			|| stat_data.st_ctime < newer_ctime_option))
		  add_to_accumulator (accumulator, "N", 1);
		else
		  add_to_accumulator (accumulator, "Y", 1);
	    }

	  add_to_accumulator (accumulator, entry, entrylen + 1);
	}

    add_to_accumulator (accumulator, "\000\000", 2);

    free (name_buffer);
    if (dirp)
      free (dirp);
  }

  /* Sort the contents of the directory, now that we have it all.  */
