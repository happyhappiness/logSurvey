 	    }
 	}
     done_header:
-      free (hdr);
+      xfree (hdr);
     }
 
   logputs (LOG_VERBOSE, "\n");
