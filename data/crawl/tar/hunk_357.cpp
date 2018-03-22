       if (lseek (fd, sparsearray[sparse_ind].offset, SEEK_SET) < 0)
 	{
 	  char buf[UINTMAX_STRSIZE_BOUND];
-	  ERROR ((0, errno, _("%s: lseek error at byte %s"),
-		  STRINGIFY_BIGINT (sparsearray[sparse_ind].offset, buf),
-		  name));
+	  int e = errno;
+	  ERROR ((0, e, _("%s: lseek error at byte %s"),
+		  quotearg_colon (name),
+		  STRINGIFY_BIGINT (sparsearray[sparse_ind].offset, buf)));
 	  return;
 	}
       written = sparsearray[sparse_ind++].numbytes;
