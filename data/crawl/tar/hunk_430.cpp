 static void
 append_file (char *path)
 {
-  int handle;
+  int handle = open (path, O_RDONLY | O_BINARY);
   struct stat stat_data;
-  off_t bytes_left;
 
-  if (stat (path, &stat_data) != 0
-      || (handle = open (path, O_RDONLY | O_BINARY), handle < 0))
+  if (handle < 0)
     {
       ERROR ((0, errno, _("Cannot open file %s"), path));
       return;
     }
 
-  bytes_left = stat_data.st_size;
-
-  while (bytes_left > 0)
+  if (fstat (handle, &stat_data) != 0)
+    ERROR ((0, errno, "%s", path));
+  else
     {
-      union block *start = find_next_block ();
-      size_t buffer_size = available_space_after (start);
-      ssize_t status;
-
-      if (bytes_left < buffer_size)
-	{
-	  buffer_size = bytes_left;
-	  status = buffer_size % BLOCKSIZE;
-	  if (status)
-	    memset (start->buffer + bytes_left, 0,
-		    (size_t) (BLOCKSIZE - status));
-	}
+      off_t bytes_left = stat_data.st_size;
 
-      status = safe_read (handle, start->buffer, buffer_size);
-      if (status < 0)
+      while (bytes_left > 0)
 	{
+	  union block *start = find_next_block ();
+	  size_t buffer_size = available_space_after (start);
+	  ssize_t status;
 	  char buf[UINTMAX_STRSIZE_BOUND];
-	  FATAL_ERROR ((0, errno,
-			_("Read error at byte %s reading %lu bytes in file %s"),
-			STRINGIFY_BIGINT (stat_data.st_size - bytes_left, buf),
-			(unsigned long) buffer_size, path));
-	}
-      bytes_left -= status;
 
-      set_next_block_after (start + (status - 1) / BLOCKSIZE);
+	  if (bytes_left < buffer_size)
+	    {
+	      buffer_size = bytes_left;
+	      status = buffer_size % BLOCKSIZE;
+	      if (status)
+		memset (start->buffer + bytes_left, 0,
+			(size_t) (BLOCKSIZE - status));
+	    }
 
-      if (status != buffer_size)
-	{
-	  char buf[UINTMAX_STRSIZE_BOUND];
-	  FATAL_ERROR ((0, 0, _("%s: File shrunk by %s bytes, (yark!)"),
-			path, STRINGIFY_BIGINT (bytes_left, buf)));
+	  status = safe_read (handle, start->buffer, buffer_size);
+	  if (status < 0)
+	    FATAL_ERROR ((0, errno,
+			  _("Read error at byte %s reading %lu bytes in file %s"),
+			  STRINGIFY_BIGINT (stat_data.st_size - bytes_left,
+					    buf),
+			  (unsigned long) buffer_size, path));
+	  if (status == 0)
+	    FATAL_ERROR ((0, 0, _("%s: File shrunk by %s bytes, (yark!)"),
+			  path, STRINGIFY_BIGINT (bytes_left, buf)));
+
+	  bytes_left -= status;
+
+	  set_next_block_after (start + (status - 1) / BLOCKSIZE);
 	}
     }
 
