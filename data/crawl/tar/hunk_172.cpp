     set_stat (file_name, &current_stat_info.stat, NULL, 0,
 	      ARCHIVED_PERMSTATUS, typeflag);
   else
-    {
-      mkfifo_error (file_name);
-      if (backup_option)
-	undo_last_backup ();
-    }
+    mkfifo_error (file_name);
+  return status;
 }  
 #endif
 
-/* Extract a file from the archive.  */
-void
-extract_archive (void)
+static int
+extract_mangle_wrapper (char *file_name, int typeflag)
 {
-  char typeflag;
-  char *file_name;
-
-  set_next_block_after (current_header);
-  decode_header (current_header, &current_stat_info, &current_format, 1);
-
-  if (interactive_option && !confirm ("extract", current_stat_info.file_name))
-    {
-      skip_member ();
-      return;
-    }
-
-  /* Print the block from current_header and current_stat.  */
-
-  if (verbose_option)
-    print_header (&current_stat_info, -1);
-
-  file_name = safer_name_suffix (current_stat_info.file_name, false);
-  if (strip_name_components)
-    {
-      size_t prefix_len = stripped_prefix_len (file_name, strip_name_components);
-      if (prefix_len == (size_t) -1)
-	{
-	  skip_member ();
-	  return;
-	}
-      file_name += prefix_len;
-    }
+  extract_mangle ();
+  return 0;
+}
 
-  apply_nonancestor_delayed_set_stat (file_name, 0);
+     
+static int
+extract_failure (char *file_name, int typeflag)
+{
+  return 1;
+}
 
-  /* Take a safety backup of a previously existing file.  */
+typedef int (*tar_extractor_t) (char *file_name, int typeflag);
 
-  if (backup_option && !to_stdout_option)
-    if (!maybe_backup_file (file_name, 0))
-      {
-	int e = errno;
-	ERROR ((0, e, _("%s: Was unable to backup this file"),
-		quotearg_colon (file_name)));
-	skip_member ();
-	return;
-      }
+
 
-  /* Extract the archive entry according to its type.  */
+/* Prepare to extract a file. Find extractor function.
+   Return zero if extraction should not proceed.  */
 
-  /* KLUDGE */
-  typeflag = sparse_member_p (&current_stat_info) ?
-                  GNUTYPE_SPARSE : current_header->header.typeflag;
+static int
+prepare_to_extract (char const *file_name, int typeflag, tar_extractor_t *fun)
+{
+  int rc = 1;
+  
+  if (to_stdout_option)
+    rc = 0;
 
+  /* Select the extractor */
   switch (typeflag)
     {
-    case GNUTYPE_SPARSE: /* FIXME: Shouldn't we call extract_file at once? */
+    case GNUTYPE_SPARSE:
+      *fun = extract_file;
+      rc = 1;
+      break;
+      
     case AREGTYPE:
     case REGTYPE:
     case CONTTYPE:
-
       /* Appears to be a file.  But BSD tar uses the convention that a slash
 	 suffix means a directory.  */
-
       if (current_stat_info.had_trailing_slash)
-	extract_dir (file_name, typeflag);
+	*fun = extract_dir;
       else
-	extract_file (file_name, typeflag);
+	{
+	  *fun = extract_file;
+	  rc = 1;
+	}
       break;
 
     case SYMTYPE:
-      extract_symlink (file_name);
+      *fun = extract_symlink;
       break;
-      
+
     case LNKTYPE:
-      extract_link (file_name);
+      *fun = extract_link;
       break;
 
 #if S_IFCHR
     case CHRTYPE:
       current_stat_info.stat.st_mode |= S_IFCHR;
-      extract_node (file_name, typeflag);
+      *fun = extract_node;
       break;
 #endif
 
 #if S_IFBLK
     case BLKTYPE:
       current_stat_info.stat.st_mode |= S_IFBLK;
-      extract_node (file_name, typeflag);
+      *fun = extract_node;
       break;
 #endif
 
 #if HAVE_MKFIFO || defined mkfifo
     case FIFOTYPE:
-      extract_fifo (file_name, typeflag);
+      *fun = extract_fifo;
       break;
 #endif
 
     case DIRTYPE:
     case GNUTYPE_DUMPDIR:
-      extract_dir (file_name, typeflag);
+      *fun = extract_dir;
       break;
 
     case GNUTYPE_VOLHDR:
       if (verbose_option)
 	fprintf (stdlis, _("Reading %s\n"), quote (current_stat_info.file_name));
+      *fun = NULL;
       break;
 
     case GNUTYPE_NAMES:
-      extract_mangle ();
+      *fun = extract_mangle_wrapper;
       break;
 
     case GNUTYPE_MULTIVOL:
       ERROR ((0, 0,
 	      _("%s: Cannot extract -- file is continued from another volume"),
 	      quotearg_colon (current_stat_info.file_name)));
-      skip_member ();
-      if (backup_option)
-	undo_last_backup ();
+      *fun = extract_failure;
       break;
 
     case GNUTYPE_LONGNAME:
     case GNUTYPE_LONGLINK:
       ERROR ((0, 0, _("Unexpected long name header")));
-      skip_member ();
-      if (backup_option)
-	undo_last_backup ();
+      *fun = extract_failure;
       break;
 
     default:
       WARN ((0, 0,
 	     _("%s: Unknown file type '%c', extracted as normal file"),
 	     quotearg_colon (file_name), typeflag));
-      extract_file (file_name, typeflag);
+      *fun = extract_file;
     }
+
+  /* Determine whether the extraction should proceed */
+  if (rc == 0)
+    return 0;
+  
+  switch (old_files_option)
+    {
+    case UNLINK_FIRST_OLD_FILES:
+      if (!remove_any_file (file_name, 
+                            recursive_unlink_option ? RECURSIVE_REMOVE_OPTION 
+                                                      : ORDINARY_REMOVE_OPTION)
+	  && errno && errno != ENOENT)
+	{
+	  unlink_error (file_name);
+	  return 0;
+	}
+      break;
+
+    case KEEP_NEWER_FILES:
+      if (file_newer_p (file_name, &current_stat_info))
+	{
+	  WARN ((0, 0, _("Current %s is newer"), quote (file_name)));
+	  return 0;
+	}
+      break;
+
+    default:
+      break;
+    }
+
+  return 1;
+}
+
+/* Extract a file from the archive.  */
+void
+extract_archive (void)
+{
+  char typeflag;
+  char *file_name;
+  tar_extractor_t fun;
+  
+  set_next_block_after (current_header);
+  decode_header (current_header, &current_stat_info, &current_format, 1);
+
+  if (interactive_option && !confirm ("extract", current_stat_info.file_name))
+    {
+      skip_member ();
+      return;
+    }
+
+  /* Print the block from current_header and current_stat.  */
+
+  if (verbose_option)
+    print_header (&current_stat_info, -1);
+
+  file_name = safer_name_suffix (current_stat_info.file_name, false);
+  if (strip_name_components)
+    {
+      size_t prefix_len = stripped_prefix_len (file_name, strip_name_components);
+      if (prefix_len == (size_t) -1)
+	{
+	  skip_member ();
+	  return;
+	}
+      file_name += prefix_len;
+    }
+
+  apply_nonancestor_delayed_set_stat (file_name, 0);
+
+  /* Take a safety backup of a previously existing file.  */
+
+  if (backup_option && !to_stdout_option)
+    if (!maybe_backup_file (file_name, 0))
+      {
+	int e = errno;
+	ERROR ((0, e, _("%s: Was unable to backup this file"),
+		quotearg_colon (file_name)));
+	skip_member ();
+	return;
+      }
+
+  /* Extract the archive entry according to its type.  */
+
+  /* KLUDGE */
+  typeflag = sparse_member_p (&current_stat_info) ?
+                  GNUTYPE_SPARSE : current_header->header.typeflag;
+
+  if (prepare_to_extract (file_name, typeflag, &fun))
+    {
+      if (fun && (*fun) (file_name, typeflag) && backup_option)
+	undo_last_backup ();
+    }
+  else
+    skip_member ();
+  
 }
 
 /* Extract the symbolic links whose final extraction were delayed.  */
