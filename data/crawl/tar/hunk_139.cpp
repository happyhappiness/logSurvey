 void
 list_archive (void)
 {
+  off_t block_ordinal = current_block_ordinal ();
   /* Print the header block.  */
 
   decode_header (current_header, &current_stat_info, &current_format, 0);
   if (verbose_option)
-    print_header (&current_stat_info, -1);
+    print_header (&current_stat_info, block_ordinal);
   
-  if (incremental_option && current_header->header.typeflag == GNUTYPE_DUMPDIR)
+  if (incremental_option)
     {
-      off_t size;
-      size_t written, check;
-      union block *data_block;
-
-      set_next_block_after (current_header);
-      if (multi_volume_option)
+      if (verbose_option > 2)
 	{
-	  assign_string (&save_name, current_stat_info.orig_file_name);
-	  save_totsize = current_stat_info.stat.st_size;
-	}
-      for (size = current_stat_info.stat.st_size; size > 0; size -= written)
-	{
-	  if (multi_volume_option)
-	    save_sizeleft = size;
-	  data_block = find_next_block ();
-	  if (!data_block)
-	    {
-	      ERROR ((0, 0, _("Unexpected EOF in archive")));
-	      break;		/* FIXME: What happens, then?  */
-	    }
-	  written = available_space_after (data_block);
-	  if (written > size)
-	    written = size;
-	  set_next_block_after ((union block *)
-				(data_block->buffer + written - 1));
-	  if (verbose_option > 2)
-	    list_dumpdir (data_block->buffer, written);
+	  if (current_stat_info.dumpdir)
+	    list_dumpdir (current_stat_info.dumpdir,
+			  dumpdir_size (current_stat_info.dumpdir));
 	}
-      if (multi_volume_option)
-	assign_string (&save_name, 0);
-
-      return;
     }
 
   if (multi_volume_option)
