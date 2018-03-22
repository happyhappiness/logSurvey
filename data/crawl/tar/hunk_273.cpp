   free (accumulator);
 }
 
-/*----------------------------------------------------------------------.
-| At the end of an ACCUMULATOR buffer, add a DATA block of SIZE bytes.  |
-`----------------------------------------------------------------------*/
-
+/* At the end of an ACCUMULATOR buffer, add a DATA block of SIZE bytes.  */
 static void
 add_to_accumulator (struct accumulator *accumulator,
-		    const char *data, int size)
+		    const char *data, size_t size)
 {
   if (accumulator->length + size > accumulator->allocated)
     {
       accumulator->allocated = accumulator->length + size + ACCUMULATOR_SLACK;
-      accumulator->pointer = (char *)
-	xrealloc (accumulator->pointer, (size_t) accumulator->allocated);
+      accumulator->pointer =
+	xrealloc (accumulator->pointer, accumulator->allocated);
     }
-  memcpy (accumulator->pointer + accumulator->length, data, (size_t) size);
+  memcpy (accumulator->pointer + accumulator->length, data, size);
   accumulator->length += size;
 }
 
 /* Incremental dump specialities.  */
 
-/* Current time.  */
-static time_t time_now;
+/* Which child files to save under a directory.  */
+enum children {NO_CHILDREN, CHANGED_CHILDREN, ALL_CHILDREN};
 
-/* List of directory names.  */
+/* Directory attributes.  */
 struct directory
   {
-    struct directory *next;	/* next entry in list */
-    const char *name;		/* path name of directory */
-    int device_number;		/* device number for directory */
-    int inode_number;		/* inode number for directory */
-    int allnew;
-    const char *dir_text;
+    dev_t device_number;	/* device number for directory */
+    ino_t inode_number;		/* inode number for directory */
+    enum children children;
+    bool nfs;
+    bool found;
+    char name[1];		/* path name of directory */
   };
-static struct directory *directory_list = NULL;
 
-/*-------------------------------------------------------------------.
-| Create and link a new directory entry for directory NAME, having a |
-| DEVICE_NUMBER and a INODE_NUMBER, with some TEXT.		     |
-`-------------------------------------------------------------------*/
+static Hash_table *directory_table;
 
-static void
-note_directory (char *name, dev_t device_number, ino_t inode_number,
-		const char *text)
-{
-  struct directory *directory
-    = (struct directory *) xmalloc (sizeof (struct directory));
+#if HAVE_ST_FSTYPE_STRING
+  static char const nfs_string[] = "nfs";
+# define NFS_FILE_STAT(st) (strcmp ((st).st_fstype, nfs_string) == 0)
+#else
+# define ST_DEV_MSB(st) (~ (dev_t) 0 << (sizeof (st).st_dev * CHAR_BIT - 1))
+# define NFS_FILE_STAT(st) (((st).st_dev & ST_DEV_MSB (st)) != 0)
+#endif
 
-  directory->next = directory_list;
-  directory_list = directory;
+/* Calculate the hash of a directory.  */
+static unsigned
+hash_directory (void const *entry, unsigned n_buckets)
+{
+  struct directory const *directory = entry;
+  return hash_string (directory->name, n_buckets);
+}
 
-  directory->device_number = device_number;
-  directory->inode_number = inode_number;
-  directory->name = xstrdup (name);
-  directory->dir_text = text;
-  directory->allnew = 0;
+/* Compare two directories for equality.  */
+static bool
+compare_directories (void const *entry1, void const *entry2)
+{
+  struct directory const *directory1 = entry1;
+  struct directory const *directory2 = entry2;
+  return strcmp (directory1->name, directory2->name) == 0;
 }
 
-/*------------------------------------------------------------------------.
-| Return a directory entry for a given path NAME, or NULL if none found.  |
-`------------------------------------------------------------------------*/
+/* Create and link a new directory entry for directory NAME, having a
+   device number DEV and an inode number INO, with NFS indicating
+   whether it is an NFS device and FOUND indicating whether we have
+   found that the directory exists.  */
+static struct directory *
+note_directory (char const *name, dev_t dev, ino_t ino, bool nfs, bool found)
+{
+  size_t size = offsetof (struct directory, name) + strlen (name) + 1;
+  struct directory *directory = xmalloc (size);
+
+  directory->device_number = dev;
+  directory->inode_number = ino;
+  directory->children = CHANGED_CHILDREN;
+  directory->nfs = nfs;
+  directory->found = found;
+  strcpy (directory->name, name);
+
+  if (! ((directory_table
+	  || (directory_table = hash_initialize (0, 0, hash_directory,
+						 compare_directories, 0)))
+	 && hash_insert (directory_table, directory)))
+    xalloc_die ();
+
+  return directory;
+}
 
+/* Return a directory entry for a given path NAME, or zero if none found.  */
 static struct directory *
 find_directory (char *name)
 {
-  struct directory *directory;
-
-  for (directory = directory_list;
-       directory;
-       directory = directory->next)
+  if (! directory_table)
+    return 0;
+  else
     {
-      if (!strcmp (directory->name, name))
-	return directory;
+      size_t size = offsetof (struct directory, name) + strlen (name) + 1;
+      struct directory *dir = alloca (size);
+      strcpy (dir->name, name);
+      return hash_lookup (directory_table, dir);
     }
-  return NULL;
 }
 
-/*---.
-| ?  |
-`---*/
-
 static int
-compare_dirents (const voidstar first, const voidstar second)
+compare_dirents (const void *first, const void *second)
 {
   return strcmp ((*(char *const *) first) + 1,
 		 (*(char *const *) second) + 1);
 }
 
-/*---.
-| ?  |
-`---*/
-
 char *
-get_directory_contents (char *path, int device)
+get_directory_contents (char *path, dev_t device)
 {
   struct accumulator *accumulator;
 
   /* Recursively scan the given PATH.  */
 
   {
-    DIR *dirp = opendir (path);	/* for scanning directory */
-    struct dirent *entry;	/* directory entry being scanned */
+    char *dirp = savedir (path);	/* for scanning directory */
+    char const *entry;	/* directory entry being scanned */
+    size_t entrylen;	/* length of directory entry */
     char *name_buffer;		/* directory, `/', and directory member */
-    int name_buffer_size;	/* allocated size of name_buffer, minus 2 */
-    int name_length;		/* used length in name_buffer */
+    size_t name_buffer_size;	/* allocated size of name_buffer, minus 2 */
+    size_t name_length;		/* used length in name_buffer */
     struct directory *directory; /* for checking if already already seen */
-    int all_children;
+    enum children children;
 
-    if (dirp == NULL)
+    if (! dirp)
       {
-	ERROR ((0, errno, _("Cannot open directory %s"), path));
-	return NULL;
+	if (ignore_failed_read_option)
+	  savedir_warn (path);
+	else
+	  savedir_error (path);
       }
-    errno = 0;			/* FIXME: errno should be read-only */
+    errno = 0;
 
     name_buffer_size = strlen (path) + NAME_FIELD_SIZE;
-    name_buffer = xmalloc ((size_t) (name_buffer_size + 2));
+    name_buffer = xmalloc (name_buffer_size + 2);
     strcpy (name_buffer, path);
-    if (path[strlen (path) - 1] != '/')
+    if (! ISSLASH (path[strlen (path) - 1]))
       strcat (name_buffer, "/");
     name_length = strlen (name_buffer);
 
     directory = find_directory (path);
-    all_children = directory ? directory->allnew : 0;
+    children = directory ? directory->children : CHANGED_CHILDREN;
 
     accumulator = new_accumulator ();
 
-    while (entry = readdir (dirp), entry)
-      {
-	struct stat stat_data;
+    if (dirp && children != NO_CHILDREN)
+      for (entry = dirp;
+	   (entrylen = strlen (entry)) != 0;
+	   entry += entrylen + 1)
+	{
+	  if (name_buffer_size <= entrylen + name_length)
+	    {
+	      do
+		name_buffer_size += NAME_FIELD_SIZE;
+	      while (name_buffer_size <= entrylen + name_length);
+	      name_buffer = xrealloc (name_buffer, name_buffer_size + 2);
+	    }
+	  strcpy (name_buffer + name_length, entry);
 
-	/* Skip `.' and `..'.  */
+	  if (excluded_name (name_buffer))
+	    add_to_accumulator (accumulator, "N", 1);
+	  else
+	    {
+	      struct stat stat_data;
 
-	if (is_dot_or_dotdot (entry->d_name))
-	  continue;
+	      if (deref_stat (dereference_option, name_buffer, &stat_data))
+		{
+		  if (ignore_failed_read_option)
+		    stat_warn (name_buffer);
+		  else
+		    stat_error (name_buffer);
+		  continue;
+		}
 
-	if ((int) NAMLEN (entry) + name_length >= name_buffer_size)
-	  {
-	    while ((int) NAMLEN (entry) + name_length >= name_buffer_size)
-	      name_buffer_size += NAME_FIELD_SIZE;
-	    name_buffer = (char *)
-	      xrealloc (name_buffer, (size_t) (name_buffer_size + 2));
-	  }
-	strcpy (name_buffer + name_length, entry->d_name);
-
-	if (dereference_option
-#ifdef AIX
-	    ? statx (name_buffer, &stat_data, STATSIZE, STX_HIDDEN)
-	    : statx (name_buffer, &stat_data, STATSIZE, STX_HIDDEN | STX_LINK)
-#else
-	    ? stat (name_buffer, &stat_data)
-	    : lstat (name_buffer, &stat_data)
-#endif
-	    )
-	  {
-	    ERROR ((0, errno, _("Cannot stat %s"), name_buffer));
-	    continue;
-	  }
-
-	if ((one_file_system_option && device != stat_data.st_dev)
-	    || (exclude_option && check_exclude (name_buffer)))
-	  add_to_accumulator (accumulator, "N", 1);
-
-#ifdef AIX
-	else if (S_ISHIDDEN (stat_data.st_mode))
-	  {
-	    add_to_accumulator (accumulator, "D", 1);
-	    strcat (entry->d_name, "A");
-	    entry->d_namlen++;
-	  }
+	      if (S_ISDIR (stat_data.st_mode))
+		{
+		  bool nfs = NFS_FILE_STAT (stat_data);
+
+		  if (directory = find_directory (name_buffer), directory)
+		    {
+		      /* With NFS, the same file can have two different devices
+			 if an NFS directory is mounted in multiple locations,
+			 which is relatively common when automounting.
+			 To avoid spurious incremental redumping of
+			 directories, consider all NFS devices as equal,
+			 relying on the i-node to establish differences.  */
+
+		      if (! (((directory->nfs & nfs)
+			      || directory->device_number == stat_data.st_dev)
+			     && directory->inode_number == stat_data.st_ino))
+			{
+			  if (verbose_option)
+			    WARN ((0, 0, _("%s: Directory has been renamed"),
+				   quotearg_colon (name_buffer)));
+			  directory->children = ALL_CHILDREN;
+			  directory->nfs = nfs;
+			  directory->device_number = stat_data.st_dev;
+			  directory->inode_number = stat_data.st_ino;
+			}
+		      directory->found = 1;
+		    }
+		  else
+		    {
+		      if (verbose_option)
+			WARN ((0, 0, _("%s: Directory is new"),
+			       quotearg_colon (name_buffer)));
+		      directory = note_directory (name_buffer,
+						  stat_data.st_dev,
+						  stat_data.st_ino, nfs, 1);
+		      directory->children =
+			((listed_incremental_option
+			  || newer_mtime_option <= stat_data.st_mtime
+			  || (after_date_option &&
+			      newer_ctime_option <= stat_data.st_ctime))
+			 ? ALL_CHILDREN
+			 : CHANGED_CHILDREN);
+		    }
+
+		  if (one_file_system_option && device != stat_data.st_dev)
+		    directory->children = NO_CHILDREN;
+		  else if (children == ALL_CHILDREN)
+		    directory->children = ALL_CHILDREN;
+
+		  add_to_accumulator (accumulator, "D", 1);
+		}
+
+	      else if (one_file_system_option && device != stat_data.st_dev)
+		add_to_accumulator (accumulator, "N", 1);
+
+#ifdef S_ISHIDDEN
+	      else if (S_ISHIDDEN (stat_data.st_mode))
+		{
+		  add_to_accumulator (accumulator, "D", 1);
+		  add_to_accumulator (accumulator, entry, entrylen);
+		  add_to_accumulator (accumulator, "A", 2);
+		  continue;
+		}
 #endif
 
-	else if (S_ISDIR (stat_data.st_mode))
-	  {
-	    if (directory = find_directory (name_buffer), directory)
-	      {
-		/* Devices having the high bit set are NFS devices, which are
-		   attributed somewhat randomly in automounting situations.
-		   For avoiding spurious incremental redumping of directories,
-		   we have to plainly consider all NFS devices as equal,
-		   relying on the i-node only to establish differences.  */
-
-		/* FIXME: Göran Uddeborg <goeran@uddeborg.pp.se> says, on
-		   1996-09-20, that SunOS 5/Solaris 2 uses unsigned long for
-		   the device number type.  */
-
-		if ((((short) directory->device_number >= 0
-		      || (short) stat_data.st_dev >= 0)
-		     && directory->device_number != stat_data.st_dev)
-		    || directory->inode_number != stat_data.st_ino)
-		  {
-		    if (verbose_option)
-		      WARN ((0, 0, _("Directory %s has been renamed"),
-			     name_buffer));
-		    directory->allnew = 1;
-		    directory->device_number = stat_data.st_dev;
-		    directory->inode_number = stat_data.st_ino;
-		  }
-		directory->dir_text = "";
-	      }
-	    else
-	      {
-		if (verbose_option)
-		  WARN ((0, 0, _("Directory %s is new"), name_buffer));
-		note_directory (name_buffer, stat_data.st_dev, stat_data.st_ino,
-				"");
-		directory = find_directory (name_buffer);
-		directory->allnew = 1;
-	      }
-	    if (all_children && directory)
-	      directory->allnew = 1;
-
-	    add_to_accumulator (accumulator, "D", 1);
-	  }
+	      else
+		if (children == CHANGED_CHILDREN
+		    && stat_data.st_mtime < newer_mtime_option
+		    && (!after_date_option
+			|| stat_data.st_ctime < newer_ctime_option))
+		  add_to_accumulator (accumulator, "N", 1);
+		else
+		  add_to_accumulator (accumulator, "Y", 1);
+	    }
 
-	else
-	  if (!all_children
-	      && stat_data.st_mtime < newer_mtime_option
-	      && (!after_date_option
-		  || stat_data.st_ctime < newer_ctime_option))
-	    add_to_accumulator (accumulator, "N", 1);
-	  else
-	    add_to_accumulator (accumulator, "Y", 1);
+	  add_to_accumulator (accumulator, entry, entrylen + 1);
+	}
 
-	add_to_accumulator (accumulator,
-			    entry->d_name, (int) (NAMLEN (entry) + 1));
-      }
     add_to_accumulator (accumulator, "\000\000", 2);
 
     free (name_buffer);
-    closedir (dirp);
+    if (dirp)
+      free (dirp);
   }
 
   /* Sort the contents of the directory, now that we have it all.  */
