 	    }
 	}
       request_set_header (req, "Content-Length",
-			  aprintf ("Content-Length: %ld", post_data_size),
-			  rel_value);
+			  aprintf ("%ld", post_data_size), rel_value);
     }
 
   /* Add the user headers. */
