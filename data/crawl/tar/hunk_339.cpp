 	  data_block = find_next_block ();
 	  if (! data_block)
 	    {
-	      ERROR ((0, 0, _("Unexpected EOF on archive file")));
+	      ERROR ((0, 0, _("Unexpected EOF in archive")));
 	      return;
 	    }
 	}
