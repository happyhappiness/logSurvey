 	  data_block = find_next_block ();
 	}
 
-      count = write (fd, data_block->buffer, (size_t) written);
+      count = write (fd, data_block->buffer, written);
 
       if (count < 0)
 	ERROR ((0, errno, _("%s: Could not write to file"), name));
       else if (count != written)
 	{
-	  ERROR ((0, 0, _("%s: Could only write %d of %d bytes"),
-		     name, count, totalsize));
-	  skip_file ((long) (*sizeleft));
+	  char buf1[UINTMAX_STRSIZE_BOUND];
+	  char buf2[UINTMAX_STRSIZE_BOUND];
+	  ERROR ((0, 0, _("%s: Could only write %s of %s bytes"),
+		  name,
+		  STRINGIFY_BIGINT (totalsize - *sizeleft, buf1),
+		  STRINGIFY_BIGINT (totalsize, buf2)));
+	  skip_file (*sizeleft);
 	}
 
       written -= count;
