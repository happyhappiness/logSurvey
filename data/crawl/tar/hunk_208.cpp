   sparse_dump_region,
   sparse_extract_region,
 };
+
+
+/* Star */
+
+/* Convert STAR format sparse data to internal representation
+   FIXME: Clubbers current_header! */
+static bool
+star_get_sparse_info (struct tar_sparse_file *file)
+{
+  size_t i;
+  union block *h = current_header;
+  int ext_p;
+  static enum oldgnu_add_status rc;
+  
+  /* FIXME: note this! st_size was initialized from the header
+     which actually contains archived size. The following fixes it */
+  file->stat_info->archive_file_size = file->stat_info->stat.st_size;
+  file->stat_info->stat.st_size =
+              OFF_FROM_HEADER (current_header->star_in_header.realsize);
+  
+  file->stat_info->sparse_map_size = 0;
+
+  if (h->star_in_header.prefix[0] == '\0'
+      && h->star_in_header.sp[0].offset[10] != '\0')
+    {
+      /* Old star format */
+      for (i = 0; i < SPARSES_IN_STAR_HEADER; i++)
+	{
+	  rc = oldgnu_add_sparse (file, &h->star_in_header.sp[i]);
+	  if (rc != add_ok)
+	    break;
+	}
+      ext_p = h->star_in_header.isextended;
+    }
+  else
+    ext_p = 1;
+
+  for (; rc == add_ok && ext_p; ext_p = h->star_ext_header.isextended)
+    {
+      h = find_next_block ();
+      if (!h)
+	{
+	  ERROR ((0, 0, _("Unexpected EOF in archive")));
+	  return false;
+	}
+      set_next_block_after (h);
+      for (i = 0; i < SPARSES_IN_STAR_EXT_HEADER && rc == add_ok; i++)
+	rc = oldgnu_add_sparse (file, &h->star_ext_header.sp[i]);
+    }
+
+  if (rc == add_fail)
+    {
+      ERROR ((0, 0, _("%s: invalid sparse archive member"),
+	      file->stat_info->orig_file_name));
+      return false;
+    }
+  return true;
+}
+
+
+static struct tar_sparse_optab star_optab = {
+  NULL,  /* No init function */
+  NULL,  /* No done function */
+  NULL,
+  star_get_sparse_info,
+  NULL,  /* No scan_block function */
+  NULL, /* No dump region function */ 
+  sparse_extract_region,
+};
