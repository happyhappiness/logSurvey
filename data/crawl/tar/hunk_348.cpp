 				(data_block->buffer + written - 1));
 	  if (check != written)
 	    {
-	      ERROR ((0, errno, _("Only wrote %lu of %lu bytes to file %s"),
+	      int e = errno;
+	      ERROR ((0, e, _("Only wrote %lu of %lu bytes to file %s"),
 		      (unsigned long) check,
-		      (unsigned long) written, current_file_name));
+		      (unsigned long) written, quote (current_file_name)));
 	      skip_file (size - written);
 	      break;
 	    }
