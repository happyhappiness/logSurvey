 	  *sizeleft -= count;
 	  set_next_block_after (data_block);
 	  data_block = find_next_block ();
+	  if (! data_block)
+	    {
+	      ERROR ((0, 0, _("Unexpected EOF on archive file")));
+	      return;
+	    }
 	}
 
       count = full_write (fd, data_block->buffer, written);
