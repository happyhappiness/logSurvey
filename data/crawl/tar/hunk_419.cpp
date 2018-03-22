 	  count = maximum < BLOCKSIZE ? maximum : BLOCKSIZE;
 	  status = full_write (STDOUT_FILENO, cursor, count);
 	  if (status < 0)
-	    FATAL_ERROR ((0, errno, _("\
-Cannot write to compression program")));
+	    FATAL_ERROR ((0, errno, _("Cannot write to compression program")));
 
 	  if (status != count)
 	    {
-	      ERROR ((0, 0, _("\
-Write to compression program short %lu bytes"),
+	      ERROR ((0, 0, _("Write to compression program short %lu bytes"),
 		      (unsigned long) (count - status)));
 	      count = status;
 	    }
