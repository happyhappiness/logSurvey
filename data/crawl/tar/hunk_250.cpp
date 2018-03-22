 	    {
 	      char message[MESSAGE_BUFFER_SIZE];
 
-	      sprintf (message, _("Could only read %lu of %lu bytes"),
+	      sprintf (message,
+		       ngettext ("Could only read %lu of %lu byte",
+				 "Could only read %lu of %lu bytes",
+				 chunk_size),
 		       (unsigned long) status, (unsigned long) chunk_size);
 	      report_difference (message);
 	    }
