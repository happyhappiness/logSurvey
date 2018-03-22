 				(data_block->buffer + written - 1));
 	  if (check != written)
 	    {
-	      int e = errno;
-	      ERROR ((0, e, _("Only wrote %lu of %lu bytes to file %s"),
-		      (unsigned long) check,
-		      (unsigned long) written, quote (current_file_name)));
+	      write_error_details (current_file_name, check, written);
 	      skip_file (size - written);
 	      break;
 	    }
