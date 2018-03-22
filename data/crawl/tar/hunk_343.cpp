 	    /* Error in writing to file.  Print it, skip to next file in
 	       archive.  */
 
-	    if (sstatus < 0)
-	      write_error (CURRENT_FILE_NAME);
-	    else
-	      ERROR ((0, 0, _("%s: Could only write %lu of %lu bytes"),
-		      quotearg_colon (CURRENT_FILE_NAME),
-		      (unsigned long) sstatus,
-		      (unsigned long) written));
+	    write_error_details (CURRENT_FILE_NAME, sstatus, written);
 	    skip_file (size - written);
 	    break;		/* still do the close, mod time, chmod, etc */
 	  }
