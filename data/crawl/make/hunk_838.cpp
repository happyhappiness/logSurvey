   return new;
 }
 
-/* Rehash FILE to NAME.  This is not as simple as resetting
-   the `hname' member, since it must be put in a new hash bucket,
-   and possibly merged with an existing file called NAME.  */
-
-void
-rehash_file (file, name)
-     register struct file *file;
-     char *name;
-{
-  char *oldname = file->hname;
-  register unsigned int oldhash;
-  register char *n;
-
-  while (file->renamed != 0)
-    file = file->renamed;
-
-  /* Find the hash values of the old and new names.  */
-
-  oldhash = 0;
-  for (n = oldname; *n != '\0'; ++n)
-    HASHI (oldhash, *n);
-
-  file_hash_enter (file, name, oldhash, file->name);
-}
-
 /* Rename FILE to NAME.  This is not as simple as resetting
    the `name' member, since it must be put in a new hash bucket,
    and possibly merged with an existing file called NAME.  */
 
 void
-rename_file (file, name)
-     register struct file *file;
-     char *name;
+rename_file (from_file, to_hname)
+     register struct file *from_file;
+     char *to_hname;
 {
-  rehash_file(file, name);
-  while (file)
+  rehash_file (from_file, to_hname);
+  while (from_file)
     {
-      file->name = file->hname;
-      file = file->prev;
+      from_file->name = from_file->hname;
+      from_file = from_file->prev;
     }
 }
 
+/* Rehash FILE to NAME.  This is not as simple as resetting
+   the `hname' member, since it must be put in a new hash bucket,
+   and possibly merged with an existing file called NAME.  */
+
 void
-file_hash_enter (file, name, oldhash, oldname)
-     register struct file *file;
-     char *name;
-     unsigned int oldhash;
-     char *oldname;
+rehash_file (from_file, to_hname)
+     register struct file *from_file;
+     char *to_hname;
 {
-  unsigned int oldbucket = oldhash % FILE_BUCKETS;
-  register unsigned int newhash, newbucket;
-  struct file *oldfile;
-  register char *n;
-  register struct file *f;
-
-  newhash = 0;
-  for (n = name; *n != '\0'; ++n)
-    HASHI (newhash, *n);
-  newbucket = newhash % FILE_BUCKETS;
-
-  /* Look for an existing file under the new name.  */
-
-  for (oldfile = files[newbucket]; oldfile != 0; oldfile = oldfile->next)
-    if (strieq (oldfile->hname, name))
-      break;
-
-  /* If the old file is the same as the new file, never mind.  */
-  if (oldfile == file)
+  struct file file_key;
+  struct file **file_slot;
+  struct file *to_file;
+  struct file *deleted_file;
+  struct file *f;
+
+  file_key.hname = to_hname;
+  if (0 == file_hash_cmp (from_file, &file_key))
     return;
 
-  if (oldhash != 0 && (newbucket != oldbucket || oldfile != 0))
-    {
-      /* Remove FILE from its hash bucket.  */
-
-      struct file *lastf = 0;
+  file_key.hname = from_file->hname;
+  while (from_file->renamed != 0)
+    from_file = from_file->renamed;
+  if (file_hash_cmp (from_file, &file_key))
+    /* hname changed unexpectedly */
+    abort ();
 
-      for (f = files[oldbucket]; f != file; f = f->next)
-	lastf = f;
-
-      if (lastf == 0)
-	files[oldbucket] = f->next;
-      else
-	lastf->next = f->next;
-    }
+  deleted_file = hash_delete (&files, from_file);
+  if (deleted_file != from_file)
+    /* from_file isn't the one stored in files */
+    abort ();
 
-  /* Give FILE its new name.  */
+  file_key.hname = to_hname;
+  file_slot = (struct file **) hash_find_slot (&files, &file_key);
+  to_file = *file_slot;
 
-  file->hname = name;
-  for (f = file->double_colon; f != 0; f = f->prev)
-    f->hname = name;
+  from_file->hname = to_hname;
+  for (f = from_file->double_colon; f != 0; f = f->prev)
+    f->hname = to_hname;
 
-  if (oldfile == 0)
-    {
-      /* There is no existing file with the new name.  */
-
-      if (newbucket != oldbucket)
-	{
-	  /* Put FILE in its new hash bucket.  */
-	  file->next = files[newbucket];
-	  files[newbucket] = file;
-	}
-    }
+  if (HASH_VACANT (to_file))
+    hash_insert_at (&files, from_file, file_slot);
   else
     {
-      /* There is an existing file with the new name.
-	 We must merge FILE into the existing file.  */
-
-      register struct dep *d;
+      /* TO_FILE already exists under TO_HNAME.
+	 We must retain TO_FILE and merge FROM_FILE into it.  */
 
-      if (file->cmds != 0)
+      if (from_file->cmds != 0)
 	{
-	  if (oldfile->cmds == 0)
-	    oldfile->cmds = file->cmds;
-	  else if (file->cmds != oldfile->cmds)
+	  if (to_file->cmds == 0)
+	    to_file->cmds = from_file->cmds;
+	  else if (from_file->cmds != to_file->cmds)
 	    {
 	      /* We have two sets of commands.  We will go with the
 		 one given in the rule explicitly mentioning this name,
 		 but give a message to let the user know what's going on.  */
-	      if (oldfile->cmds->fileinfo.filenm != 0)
-                error (&file->cmds->fileinfo,
-                                _("Commands were specified for \
-file `%s' at %s:%lu,"),
-                                oldname, oldfile->cmds->fileinfo.filenm,
-                                oldfile->cmds->fileinfo.lineno);
+	      if (to_file->cmds->fileinfo.filenm != 0)
+                error (&from_file->cmds->fileinfo,
+		       _("Commands were specified for file `%s' at %s:%lu,"),
+		       from_file->name, to_file->cmds->fileinfo.filenm,
+		       to_file->cmds->fileinfo.lineno);
 	      else
-		error (&file->cmds->fileinfo,
-				_("Commands for file `%s' were found by \
-implicit rule search,"),
-				oldname);
-	      error (&file->cmds->fileinfo,
-			      _("but `%s' is now considered the same file \
-as `%s'."),
-			      oldname, name);
-	      error (&file->cmds->fileinfo,
-			      _("Commands for `%s' will be ignored \
-in favor of those for `%s'."),
-			      name, oldname);
+		error (&from_file->cmds->fileinfo,
+		       _("Commands for file `%s' were found by implicit rule search,"),
+		       from_file->name);
+	      error (&from_file->cmds->fileinfo,
+		     _("but `%s' is now considered the same file as `%s'."),
+		     from_file->name, to_hname);
+	      error (&from_file->cmds->fileinfo,
+		     _("Commands for `%s' will be ignored in favor of those for `%s'."),
+		     to_hname, from_file->name);
 	    }
 	}
 
       /* Merge the dependencies of the two files.  */
 
-      d = oldfile->deps;
-      if (d == 0)
-	oldfile->deps = file->deps;
+      if (to_file->deps == 0)
+	to_file->deps = from_file->deps;
       else
 	{
-	  while (d->next != 0)
-	    d = d->next;
-	  d->next = file->deps;
+	  register struct dep *deps = to_file->deps;
+	  while (deps->next != 0)
+	    deps = deps->next;
+	  deps->next = from_file->deps;
 	}
 
-      merge_variable_set_lists (&oldfile->variables, file->variables);
+      merge_variable_set_lists (&to_file->variables, from_file->variables);
 
-      if (oldfile->double_colon && file->is_target && !file->double_colon)
+      if (to_file->double_colon && from_file->is_target && !from_file->double_colon)
 	fatal (NILF, _("can't rename single-colon `%s' to double-colon `%s'"),
-	       oldname, name);
-      if (!oldfile->double_colon  && file->double_colon)
+	       from_file->name, to_hname);
+      if (!to_file->double_colon  && from_file->double_colon)
 	{
-	  if (oldfile->is_target)
+	  if (to_file->is_target)
 	    fatal (NILF, _("can't rename double-colon `%s' to single-colon `%s'"),
-		   oldname, name);
+		   from_file->name, to_hname);
 	  else
-	    oldfile->double_colon = file->double_colon;
+	    to_file->double_colon = from_file->double_colon;
 	}
 
-      if (file->last_mtime > oldfile->last_mtime)
+      if (from_file->last_mtime > to_file->last_mtime)
 	/* %%% Kludge so -W wins on a file that gets vpathized.  */
-	oldfile->last_mtime = file->last_mtime;
+	to_file->last_mtime = from_file->last_mtime;
 
-      oldfile->mtime_before_update = file->mtime_before_update;
+      to_file->mtime_before_update = from_file->mtime_before_update;
 
-#define MERGE(field) oldfile->field |= file->field
+#define MERGE(field) to_file->field |= from_file->field
       MERGE (precious);
       MERGE (tried_implicit);
       MERGE (updating);
