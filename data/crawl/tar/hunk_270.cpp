 
       previous_status = status;
     }
+  while (logical_status == HEADER_STILL_UNREAD);
 
-  if (logical_status != HEADER_SUCCESS)
-    {
-      write_eot ();
-      close_archive ();
-      names_notfound ();
-      return;
-    }
-
-  write_archive_to_stdout = 0;
-  new_record = (union block *) xmalloc ((size_t) record_size);
-
-  /* Save away blocks before this one in this record.  */
+  records_skipped = records_read - 1;
+  new_record = xmalloc (record_size);
 
-  new_blocks = current_block - record_start;
-  blocks_needed = blocking_factor - new_blocks;
-  if (new_blocks)
-    memcpy ((void *) new_record, (void *) record_start,
-	   (size_t) (new_blocks * BLOCKSIZE));
-
-#if 0
-  /* FIXME: Old code, before the goto was inserted.  To be redesigned.  */
-  set_next_block_after (current_header);
-  if (current_header->oldgnu_header.isextended)
-    skip_extended_headers ();
-  skip_file ((long) (current_stat.st_size));
-#endif
-  logical_status = HEADER_STILL_UNREAD;
-  goto flush_file;
-
-  /* FIXME: Solaris 2.4 Sun cc (the ANSI one, not the old K&R) says:
-       "delete.c", line 223: warning: loop not entered at top
-     Reported by Bruno Haible.  */
-  while (1)
+  if (logical_status == HEADER_SUCCESS
+      || logical_status == HEADER_SUCCESS_EXTENDED)
     {
-      enum read_header status;
+      write_archive_to_stdout = 0;
 
-      /* Fill in a record.  */
+      /* Save away blocks before this one in this record.  */
 
-      if (current_block == record_end)
-	{
-	  flush_archive ();
-	  records_read++;
-	}
-      status = read_header ();
+      new_blocks = current_block - record_start;
+      if (new_blocks)
+	memcpy (new_record, record_start, new_blocks * BLOCKSIZE);
 
-      if (status == HEADER_ZERO_BLOCK && ignore_zeros_option)
+      if (logical_status == HEADER_SUCCESS)
 	{
-	  set_next_block_after (current_header);
-	  continue;
-	}
-      if (status == HEADER_END_OF_FILE || status == HEADER_ZERO_BLOCK)
-	{
-	  logical_status = HEADER_END_OF_FILE;
-	  memset (new_record[new_blocks].buffer, 0,
-		 (size_t) (BLOCKSIZE * blocks_needed));
-	  new_blocks += blocks_needed;
-	  blocks_needed = 0;
-	  write_record (0);
-	  break;
+	  /* FIXME: Pheew!  This is crufty code!  */
+	  logical_status = HEADER_STILL_UNREAD;
+	  goto flush_file;
 	}
 
-      if (status == HEADER_FAILURE)
+      /* FIXME: Solaris 2.4 Sun cc (the ANSI one, not the old K&R) says:
+	 "delete.c", line 223: warning: loop not entered at top
+	 Reported by Bruno Haible.  */
+      while (1)
 	{
-	  ERROR ((0, 0, _("Deleting non-header from archive")));
-	  set_next_block_after (current_header);
-	  continue;
-	}
+	  enum read_header status;
 
-      /* Found another header.  */
+	  /* Fill in a record.  */
 
-      if (name = name_scan (current_file_name), name)
-	{
-	  name->found = 1;
-	flush_file:
-	  set_next_block_after (current_header);
-	  blocks_to_skip = (current_stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
+	  if (current_block == record_end)
+	    flush_archive ();
+	  status = read_header (0);
 
-	  while (record_end - current_block <= blocks_to_skip)
+	  if (status == HEADER_ZERO_BLOCK && ignore_zeros_option)
 	    {
-	      blocks_to_skip -= (record_end - current_block);
-	      flush_archive ();
-	      records_read++;
+	      set_next_block_after (current_header);
+	      continue;
+	    }
+	  if (status == HEADER_END_OF_FILE || status == HEADER_ZERO_BLOCK)
+	    {
+	      logical_status = HEADER_END_OF_FILE;
+	      break;
 	    }
-	  current_block += blocks_to_skip;
-	  blocks_to_skip = 0;
-	  continue;
-	}
 
-      /* Copy header.  */
+	  if (status == HEADER_FAILURE)
+	    {
+	      ERROR ((0, 0, _("Deleting non-header from archive")));
+	      set_next_block_after (current_header);
+	      continue;
+	    }
 
-      new_record[new_blocks] = *current_header;
-      new_blocks++;
-      blocks_needed--;
-      blocks_to_keep
-	= (current_stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
-      set_next_block_after (current_header);
-      if (blocks_needed == 0)
-	write_record (1);
+	  /* Found another header.  */
+
+	  if (name = name_scan (current_stat_info.file_name), name)
+	    {
+	      name->found = 1;
+	    flush_file:
+	      set_next_block_after (current_header);
+	      blocks_to_skip = (current_stat_info.stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
+
+	      while (record_end - current_block <= blocks_to_skip)
+		{
+		  blocks_to_skip -= (record_end - current_block);
+		  flush_archive ();
+		}
+	      current_block += blocks_to_skip;
+	      blocks_to_skip = 0;
+	      continue;
+	    }
 
-      /* Copy data.  */
+	  /* Copy header.  */
 
-      kept_blocks_in_record = record_end - current_block;
-      if (kept_blocks_in_record > blocks_to_keep)
-	kept_blocks_in_record = blocks_to_keep;
+	  write_recent_blocks (recent_long_name, recent_long_name_blocks);
+	  write_recent_blocks (recent_long_link, recent_long_link_blocks);
+	  new_record[new_blocks] = *current_header;
+	  new_blocks++;
+	  blocks_to_keep
+	    = (current_stat_info.stat.st_size + BLOCKSIZE - 1) / BLOCKSIZE;
+	  set_next_block_after (current_header);
+	  if (new_blocks == blocking_factor)
+	    write_record (1);
 
-      while (blocks_to_keep)
-	{
-	  int count;
+	  /* Copy data.  */
 
-	  if (current_block == record_end)
+	  kept_blocks_in_record = record_end - current_block;
+	  if (kept_blocks_in_record > blocks_to_keep)
+	    kept_blocks_in_record = blocks_to_keep;
+
+	  while (blocks_to_keep)
 	    {
-	      flush_read ();
-	      records_read++;
-	      current_block = record_start;
-	      kept_blocks_in_record = blocking_factor;
-	      if (kept_blocks_in_record > blocks_to_keep)
-		kept_blocks_in_record = blocks_to_keep;
+	      int count;
+
+	      if (current_block == record_end)
+		{
+		  flush_read ();
+		  current_block = record_start;
+		  kept_blocks_in_record = blocking_factor;
+		  if (kept_blocks_in_record > blocks_to_keep)
+		    kept_blocks_in_record = blocks_to_keep;
+		}
+	      count = kept_blocks_in_record;
+	      if (blocking_factor - new_blocks < count)
+		count = blocking_factor - new_blocks;
+
+	      if (! count)
+		abort ();
+
+	      memcpy (new_record + new_blocks, current_block, count * BLOCKSIZE);
+	      new_blocks += count;
+	      current_block += count;
+	      blocks_to_keep -= count;
+	      kept_blocks_in_record -= count;
+
+	      if (new_blocks == blocking_factor)
+		write_record (1);
 	    }
-	  count = kept_blocks_in_record;
-	  if (count > blocks_needed)
-	    count = blocks_needed;
-
-	  memcpy ((void *) (new_record + new_blocks),
-		  (void *) current_block,
-		  (size_t) (count * BLOCKSIZE));
-	  new_blocks += count;
-	  blocks_needed -= count;
-	  current_block += count;
-	  blocks_to_keep -= count;
-	  kept_blocks_in_record -= count;
-
-	  if (blocks_needed == 0)
-	    write_record (1);
 	}
     }
 
-  write_eot ();
+  if (logical_status == HEADER_END_OF_FILE)
+    {
+      /* Write the end of tape.  FIXME: we can't use write_eot here,
+	 as it gets confused when the input is at end of file.  */
+
+      int total_zero_blocks = 0;
+
+      do
+	{
+	  int zero_blocks = blocking_factor - new_blocks;
+	  memset (new_record + new_blocks, 0, BLOCKSIZE * zero_blocks);
+	  total_zero_blocks += zero_blocks;
+	  write_record (total_zero_blocks < 2);
+	}
+      while (total_zero_blocks < 2);
+    }
+
+  free (new_record);
+
+  if (! acting_as_filter && ! _isrmt (archive))
+    {
+#if MSDOS
+      int status = write (archive, "", 0);
+#else
+      off_t pos = lseek (archive, (off_t) 0, SEEK_CUR);
+      int status = pos < 0 ? -1 : ftruncate (archive, pos);
+#endif
+      if (status != 0)
+	truncate_warn (archive_name_array[0]);
+    }
+
   close_archive ();
   names_notfound ();
 }
