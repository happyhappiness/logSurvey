 	if (read_header (&header, &dummy, read_header_x_global)
 	    != HEADER_SUCCESS_EXTENDED)
 	  {
-	    ERROR ((0, 0, _("This does not look like a tar archive")));
+	    WARN ((0, 0, _("This does not look like a tar archive")));
 	    return false;
 	  }
 
