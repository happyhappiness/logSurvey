       if (!bufsize)
 	{
 	  /* We blew it, maybe.  */
+	  char buf1[UINTMAX_STRSIZE_BOUND];
+	  char buf2[UINTMAX_STRSIZE_BOUND];
+
+	  ERROR ((0, 0, _("Wrote %s of %s bytes to file %s"),
+		  STRINGIFY_BIGINT (fullsize - *sizeleft, buf1),
+		  STRINGIFY_BIGINT (fullsize, buf2),
+		  name));
+	  break;
+	}
 
-	  ERROR ((0, 0, _("Wrote %ld of %ld bytes to file %s"),
-		  fullsize - *sizeleft, fullsize, name));
+      if (lseek (file, sparsearray[sparse_index++].offset, 0) < 0)
+	{
+	  char buf[UINTMAX_STRSIZE_BOUND];
+	  ERROR ((0, errno, _("lseek error at byte %s in file %s"),
+		  STRINGIFY_BIGINT (sparsearray[sparse_index - 1].offset, buf),
+		  name));
 	  break;
 	}
-      pos = lseek (file, sparsearray[sparse_index++].offset, 0);
 
       /* If the number of bytes to be written here exceeds the size of
 	 the temporary buffer, do it in steps.  */
