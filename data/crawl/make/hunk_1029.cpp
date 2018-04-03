 					  | (noerror ? RM_DONTCARE : 0)))
 		  && ! noerror)
 		error (&fileinfo, "%s: %s", name, strerror (errno));
-              free(name);
+
+              /* We can't free NAME here, in case some of the commands,
+                 etc. still contain references to the filename.  */
 	    }
 
 	  /* Free any space allocated by conditional_line.  */
