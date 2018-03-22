       if (! data_block)
 	{
 	  ERROR ((0, 0, _("Unexpected EOF in archive")));
-	  return;
+	  return sizeleft;
 	}
       if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
 	{
 	  seek_error_details (name, sparsearray[sparse_ind].offset);
-	  return;
+	  return sizeleft;
 	}
       written = sparsearray[sparse_ind++].numbytes;
       while (written > BLOCKSIZE)
 	{
 	  count = full_write (fd, data_block->buffer, BLOCKSIZE);
 	  written -= count;
-	  *sizeleft -= count;
+	  sizeleft -= count;
 	  if (count != BLOCKSIZE)
 	    {
 	      write_error_details (name, count, BLOCKSIZE);
-	      return;
+	      return sizeleft;
 	    }
 	  set_next_block_after (data_block);
 	  data_block = find_next_block ();
 	  if (! data_block)
 	    {
 	      ERROR ((0, 0, _("Unexpected EOF in archive")));
-	      return;
+	      return sizeleft;
 	    }
 	}
 
       count = full_write (fd, data_block->buffer, written);
-      *sizeleft -= count;
+      sizeleft -= count;
 
       if (count != written)
 	{
 	  write_error_details (name, count, written);
-	  return;
+	  return sizeleft;
 	}
 
       set_next_block_after (data_block);
     }
+
+  if (ftruncate (fd, file_size) != 0)
+    truncate_error (name);
+
+  return 0;
 }
 
 /* Fix the statuses of all directories whose statuses need fixing, and
