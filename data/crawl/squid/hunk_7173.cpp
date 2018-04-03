     FD_ENTRY *fde = &fd_table[fd];
     if (len < 0)
 	return;
+    assert (type == FD_READ || type == FD_WRITE);
     if (type == FD_READ)
 	fde->bytes_read += len;
-    else if (type == FD_WRITE)
-	fde->bytes_written += len;
     else
-	fatal_dump("fd_bytes: bad type");
+	fde->bytes_written += len;
 }
 
 void
