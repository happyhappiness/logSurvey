   return (tar_sparse_done (&file) && rc) ? dump_status_ok : dump_status_short;
 }
 
+
+static char diff_buffer[BLOCKSIZE];
+		   
+static bool
+check_sparse_region (struct tar_sparse_file *file, off_t beg, off_t end)
+{
+  if (!lseek_or_error (file, beg, SEEK_SET))
+    return false;
+  
+  while (beg < end)
+    {
+      size_t bytes_read;
+      size_t rdsize = end - beg;
+      
+      if (rdsize > BLOCKSIZE)
+	rdsize = BLOCKSIZE;
+      clear_block (diff_buffer);
+      bytes_read = safe_read (file->fd, diff_buffer, rdsize);
+      if (bytes_read < 0)
+	{
+          read_diag_details (file->stat_info->orig_file_name,
+	                     beg,
+			     rdsize);
+	  return false;
+	}
+      if (!zero_block_p (diff_buffer, bytes_read))
+	{
+ 	  report_difference (file->stat_info,
+			     _("File fragment at %lu is not a hole"), beg);
+	  return false;
+	}
+
+      beg += bytes_read;
+    }
+  return true;
+}
+
+static bool
+check_data_region (struct tar_sparse_file *file, size_t index)
+{
+  size_t size_left;
+  
+  if (!lseek_or_error (file, file->stat_info->sparse_map[index].offset,
+		       SEEK_SET))
+    return false;
+  size_left = file->stat_info->sparse_map[index].numbytes;
+  while (size_left > 0)
+    {
+      size_t bytes_read;
+      size_t rdsize = (size_left > BLOCKSIZE) ? BLOCKSIZE : size_left;
+      
+      union block *blk = find_next_block ();
+      if (!blk)
+	{
+	  ERROR ((0, 0, _("Unexpected EOF in archive")));
+	  return false;
+	}
+      set_next_block_after (blk);
+      bytes_read = safe_read (file->fd, diff_buffer, rdsize);
+      if (bytes_read < 0)
+	{
+          read_diag_details (file->stat_info->orig_file_name,
+			     file->stat_info->sparse_map[index].offset
+	                         + file->stat_info->sparse_map[index].numbytes
+			         - size_left,
+			     rdsize);
+	  return false;
+	}
+      file->dumped_size += bytes_read;
+      size_left -= bytes_read;
+      if (memcmp (blk->buffer, diff_buffer, rdsize))
+	{
+	  report_difference (file->stat_info, _("Contents differ"));
+	  return false;
+	}
+    }
+  return true;
+}
+
+bool
+sparse_diff_file (int fd, struct tar_stat_info *stat)
+{
+  bool rc = true;
+  struct tar_sparse_file file;
+  size_t i;
+  off_t offset = 0;
+  
+  file.stat_info = stat;
+  file.fd = fd;
+
+  if (!sparse_select_optab (&file)
+      || !tar_sparse_init (&file))
+    return dump_status_not_implemented;
+
+  rc = tar_sparse_decode_header (&file);
+  for (i = 0; rc && i < file.stat_info->sparse_map_avail; i++)
+    {
+      rc = check_sparse_region (&file,
+				offset, file.stat_info->sparse_map[i].offset)
+	&& check_data_region (&file, i);
+      offset = file.stat_info->sparse_map[i].offset
+	        + file.stat_info->sparse_map[i].numbytes;
+    }
+
+  if (rc)
+    skip_file (file.stat_info->archive_file_size - file.dumped_size);
+
+  tar_sparse_done (&file);
+  return rc;
+}
+
      
 /* Old GNU Format. The sparse file information is stored in the
    oldgnu_header in the following manner:
