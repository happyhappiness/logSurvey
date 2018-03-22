 	}
       if (!zero_block_p (diff_buffer, bytes_read))
 	{
+	  char begbuf[INT_BUFSIZE_BOUND (off_t)];
  	  report_difference (file->stat_info,
-			     _("File fragment at %lu is not a hole"), beg);
+			     _("File fragment at %s is not a hole"),
+			     offtostr (beg, begbuf));
 	  return false;
 	}
 
