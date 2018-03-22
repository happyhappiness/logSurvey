     {
       size_t size = sparse_map[i].numbytes;
 
-      lseek (ofd, sparse_map[i].offset, SEEK_SET);
-      while (size)
+      if (size == 0)
+	ftruncate (ofd, sparse_map[i].offset);
+      else
 	{
-	  size_t rdsize = (size < maxbytes) ? size : maxbytes;
-	  if (rdsize != fread (buffer, 1, rdsize, sfp))
-	    die (1, "read error (%d)", errno);
-	  if (rdsize != write (ofd, buffer, rdsize))
-	    die (1, "write error (%d)", errno);
-	  size -= rdsize;
+	  lseek (ofd, sparse_map[i].offset, SEEK_SET);
+	  while (size)
+	    {
+	      size_t rdsize = (size < maxbytes) ? size : maxbytes;
+	      if (rdsize != fread (buffer, 1, rdsize, sfp))
+		die (1, "read error (%d)", errno);
+	      if (rdsize != write (ofd, buffer, rdsize))
+		die (1, "write error (%d)", errno);
+	      size -= rdsize;
+	    }
 	}
     }
   free (buffer);
