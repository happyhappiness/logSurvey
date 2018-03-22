     {
     case XGLTYPE:
       {
-        if (!read_header0 (&dummy))
-          return false;
+	tar_stat_init (&dummy);
+	if (read_header (&header, &dummy, read_header_x_global)
+	    != HEADER_SUCCESS_EXTENDED)
+	  {
+	    ERROR ((0, 0, _("This does not look like a tar archive")));
+	    return false;
+	  }
+	
         xheader_decode (&dummy); /* decodes values from the global header */
         tar_stat_destroy (&dummy);
-        if (!real_s_name)
-          {
-            /* We have read the extended header of the first member in
-               this volume. Put it back, so next read_header works as
-               expected. */
-            current_block = record_start;
-          }
+	
+	/* The initial global header must be immediately followed by
+	   an extended PAX header for the first member in this volume.
+	   However, in some cases tar may split volumes in the middle
+	   of a PAX header. This is incorrect, and should be fixed
+           in the future versions. In the meantime we must be
+	   prepared to correctly list and extract such archives.
+
+	   If this happens, the following call to read_header returns
+	   HEADER_FAILURE, which is ignored.
+
+	   See also tests/multiv07.at */
+	       
+	switch (read_header (&header, &dummy, read_header_auto))
+	  {
+	  case HEADER_SUCCESS:
+	    set_next_block_after (header);
+	    break;
+
+	  case HEADER_FAILURE:
+	    break;
+
+	  default:
+	    ERROR ((0, 0, _("This does not look like a tar archive")));
+	    return false;
+	  }
         break;
       }
 
