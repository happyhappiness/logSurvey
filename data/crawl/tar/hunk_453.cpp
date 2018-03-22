 				(data_block->buffer + written - 1));
 	  if (check != written)
 	    {
-	      ERROR ((0, errno, _("Only wrote %ld of %ld bytes to file %s"),
-		      check, written, current_file_name));
-	      skip_file ((long) (size - written));
+	      ERROR ((0, errno, _("Only wrote %lu of %lu bytes to file %s"),
+		      (unsigned long) check,
+		      (unsigned long) written, current_file_name));
+	      skip_file (size - written);
 	      break;
 	    }
 	}
