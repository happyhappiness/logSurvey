 	ERROR ((0, 0, _("%s: Not found in archive"), name));
     }
 }
+
+/* Sorting name lists.  */
 
-/*---.
-| ?  |
-`---*/
+/* Sort linked LIST of names, of given LENGTH, using COMPARE to order
+   names.  Return the sorted list.  Apart from the type `struct name'
+   and the definition of SUCCESSOR, this is a generic list-sorting
+   function, but it's too painful to make it both generic and portable
+   in C.  */
+
+static struct name *
+merge_sort (struct name *list, int length,
+	    int (*compare) (struct name const*, struct name const*))
+{
+  struct name *first_list;
+  struct name *second_list;
+  int first_length;
+  int second_length;
+  struct name *result;
+  struct name **merge_point;
+  struct name *cursor;
+  int counter;
+
+# define SUCCESSOR(name) ((name)->next)
+
+  if (length == 1)
+    return list;
+
+  if (length == 2)
+    {
+      if ((*compare) (list, SUCCESSOR (list)) > 0)
+	{
+	  result = SUCCESSOR (list);
+	  SUCCESSOR (result) = list;
+	  SUCCESSOR (list) = 0;
+	  return result;
+	}
+      return list;
+    }
+
+  first_list = list;
+  first_length = (length + 1) / 2;
+  second_length = length / 2;
+  for (cursor = list, counter = first_length - 1;
+       counter;
+       cursor = SUCCESSOR (cursor), counter--)
+    continue;
+  second_list = SUCCESSOR (cursor);
+  SUCCESSOR (cursor) = 0;
+
+  first_list = merge_sort (first_list, first_length, compare);
+  second_list = merge_sort (second_list, second_length, compare);
+
+  merge_point = &result;
+  while (first_list && second_list)
+    if ((*compare) (first_list, second_list) < 0)
+      {
+	cursor = SUCCESSOR (first_list);
+	*merge_point = first_list;
+	merge_point = &SUCCESSOR (first_list);
+	first_list = cursor;
+      }
+    else
+      {
+	cursor = SUCCESSOR (second_list);
+	*merge_point = second_list;
+	merge_point = &SUCCESSOR (second_list);
+	second_list = cursor;
+      }
+  if (first_list)
+    *merge_point = first_list;
+  else
+    *merge_point = second_list;
+
+  return result;
+
+#undef SUCCESSOR
+}
+
+/* A comparison function for sorting names.  Put found names last;
+   break ties by string comparison.  */
+
+static int
+compare_names (struct name const *n1, struct name const *n2)
+{
+  int found_diff = n2->found - n1->found;
+  return found_diff ? found_diff : strcmp (n1->name, n2->name);
+}
+
+/* Add all the dirs in PATH, which is a directory, to the namelist.
+   If any of the files is a directory, recurse on the subdirectory.
+   CHANGE_DIR is the number of the directory that PATH is relative to.
+   DEVICE is the device not to leave, if the -l option is specified.  */
+
+static void
+add_hierarchy_to_namelist (char *path, int change_dir, dev_t device)
+{
+  char *buffer = get_directory_contents (path, device);
+
+  {
+    struct name *name;
+
+    for (name = namelist; name; name = name->next)
+      if (strcmp (name->name, path) == 0)
+	break;
+    if (name)
+      name->dir_contents = buffer ? buffer : "\0\0\0\0";
+  }
+
+  if (buffer)
+    {
+      size_t name_length = strlen (path);
+      size_t allocated_length = (name_length >= NAME_FIELD_SIZE
+				 ? name_length + NAME_FIELD_SIZE
+				 : NAME_FIELD_SIZE);
+      char *name_buffer = xmalloc (allocated_length + 1);
+				/* FIXME: + 2 above?  */
+      char *string;
+      size_t string_length;
+
+      strcpy (name_buffer, path);
+      if (name_buffer[name_length - 1] != '/')
+	{
+	  name_buffer[name_length++] = '/';
+	  name_buffer[name_length] = '\0';
+	}
+
+      for (string = buffer; *string; string += string_length + 1)
+	{
+	  string_length = strlen (string);
+	  if (*string == 'D')
+	    {
+	      if (name_length + string_length >= allocated_length)
+		{
+		  while (name_length + string_length >= allocated_length)
+		    allocated_length += NAME_FIELD_SIZE;
+		  name_buffer = xrealloc (name_buffer, allocated_length + 1);
+		}
+	      strcpy (name_buffer + name_length, string + 1);
+	      addname (name_buffer, change_dir);
+	      if (*string == 'D')
+		add_hierarchy_to_namelist (name_buffer, change_dir, device);
+	    }
+	}
+
+      free (name_buffer);
+    }
+}
+
+/* Collect all the names from argv[] (or whatever), expand them into a
+   directory tree, and sort them.  This gets only subdirectories, not
+   all files.  */
 
 void
-name_expand (void)
+collect_and_sort_names (void)
 {
+  struct name *name;
+  struct name *next_name;
+  int num_names;
+  struct stat statbuf;
+
+  name_gather ();
+
+  if (listed_incremental_option)
+    read_directory_file ();
+
+  if (!namelist)
+    addname (".", 0);
+
+  for (name = namelist; name; name = next_name)
+    {
+      next_name = name->next;
+      if (name->found || name->dir_contents)
+	continue;
+      if (name->regexp)		/* FIXME: just skip regexps for now */
+	continue;
+      chdir_do (name->change_dir);
+      if (name->fake)
+	continue;
+
+      if (deref_stat (dereference_option, name->name, &statbuf) != 0)
+	{
+	  ERROR ((0, errno, _("Cannot stat %s"), name->name));
+	  continue;
+	}
+      if (S_ISDIR (statbuf.st_mode))
+	{
+	  name->found = 1;
+	  add_hierarchy_to_namelist (name->name, name->change_dir,
+				     statbuf.st_dev);
+	}
+    }
+
+  num_names = 0;
+  for (name = namelist; name; name = name->next)
+    num_names++;
+  namelist = merge_sort (namelist, num_names, compare_names);
+
+  for (name = namelist; name; name = name->next)
+    name->found = 0;
 }
 
 /*-------------------------------------------------------------------------.
