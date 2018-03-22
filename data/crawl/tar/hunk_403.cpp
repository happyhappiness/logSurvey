       goto error_loop;		/* try again */
     }
 
-short_read:
+ short_read:
   more = record_start->buffer + status;
   left = record_size - status;
 
-again:
-  if (left % BLOCKSIZE == 0)
+  while (left % BLOCKSIZE != 0)
     {
-      /* FIXME: for size=0, multi-volume support.  On the first record, warn
-	 about the problem.  */
-
-      if (!read_full_records_option && verbose_option
-	  && record_start_block == 0 && status > 0)
-	WARN ((0, 0, _("Record size = %lu blocks"),
-	       (unsigned long) (status / BLOCKSIZE)));
+      while ((status = rmtread (archive, more, left)) < 0)
+	read_error ();
 
-      record_end = record_start + (record_size - left) / BLOCKSIZE;
+      if (status == 0)
+	{
+	  ERROR ((0, 0, _("%d garbage bytes ignored at end of archive"),
+		  (int) ((record_size - left) % BLOCKSIZE)));
+	  break;
+	}
 
-      return;
-    }
-  if (read_full_records_option)
-    {
+      if (! read_full_records_option)
+	FATAL_ERROR ((0, 0, _("Unaligned block (%lu bytes) in archive"),
+		      (unsigned long) (record_size - left)));
+	  
       /* User warned us about this.  Fix up.  */
 
-      if (left > 0)
-	{
-	error2loop:
-	  status = rmtread (archive, more, left);
-	  if (status < 0)
-	    {
-	      read_error ();
-	      goto error2loop;	/* try again */
-	    }
-	  if (status == 0)
-	    FATAL_ERROR ((0, 0, _("Archive %s EOF not on block boundary"),
-			  *archive_name_cursor));
-	  left -= status;
-	  more += status;
-	  goto again;
-	}
+      left -= status;
+      more += status;
     }
-  else
-    FATAL_ERROR ((0, 0, _("Only read %lu bytes from archive %s"),
-		  (unsigned long) status, *archive_name_cursor));
+
+  /* FIXME: for size=0, multi-volume support.  On the first record, warn
+     about the problem.  */
+
+  if (!read_full_records_option && verbose_option
+      && record_start_block == 0 && status > 0)
+    WARN ((0, 0, _("Record size = %lu blocks"),
+	   (unsigned long) ((record_size - left) / BLOCKSIZE)));
+
+  record_end = record_start + (record_size - left) / BLOCKSIZE;
 }
 
 /*-----------------------------------------------.
