 	    {
 	      struct nameseq *next = files->next;
 	      char *name = files->name;
+              int r;
+
 	      free ((char *)files);
 	      files = next;
 
-	      if (! read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
-					  | (noerror ? RM_DONTCARE : 0)))
-		  && ! noerror)
+              r = read_makefile (name, (RM_INCLUDED | RM_NO_TILDE
+                                        | (noerror ? RM_DONTCARE : 0)));
+	      if (!r && !noerror)
 		error (&fileinfo, "%s: %s", name, strerror (errno));
 
-              /* We can't free NAME here, in case some of the commands,
-                 etc. still contain references to the filename.  */
+              if (r < 2)
+                free (name);
 	    }
 
 	  /* Free any space allocated by conditional_line.  */
