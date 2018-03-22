 	char buffer[BLOCKSIZE];
 
 	clear_buffer (buffer);
-	count = read (file, buffer, (size_t) bufsize);
+	count = read (file, buffer, bufsize);
 	memcpy (start->buffer, buffer, BLOCKSIZE);
       }
 
       if (count < 0)
 	{
+	  char buf[UINTMAX_STRSIZE_BOUND];
+	  
 	  ERROR ((0, errno,
-		  _("Read error at byte %ld, reading %d bytes, in file %s"),
-		  fullsize - *sizeleft, bufsize, name));
+		  _("Read error at byte %s, reading %lu bytes, in file %s"),
+		  STRINGIFY_BIGINT (fullsize - *sizeleft, buf),
+		  (unsigned long) bufsize, name));
 	  return 1;
 	}
 #if 0
