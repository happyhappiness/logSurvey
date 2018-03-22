 	      if (status < 0)
 		{
 		  read_error (current_stat_info.file_name);
-		  report_difference (0);
+		  report_difference (NULL);
 		}
 	      else
 		{
-		  char message[MESSAGE_BUFFER_SIZE];
-
-		  sprintf (message,
-			   ngettext ("Could only read %lu of %lu byte",
+		  report_difference (ngettext ("Could only read %lu of %lu byte",
 				     "Could only read %lu of %lu bytes",
 				     chunk_size),
-			   (unsigned long) status, (unsigned long) chunk_size);
-		  report_difference (message);
+				     (unsigned long) status,
+				     (unsigned long) chunk_size);
 		}
 	      break;
 	    }
