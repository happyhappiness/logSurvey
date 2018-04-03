 	  int noerror = (p[0] != 'i');
 
 	  p = allocated_variable_expand (p2);
+
+          /* If no filenames, it's a no-op.  */
 	  if (*p == '\0')
-	    {
-	      error (fstart,
-                     _("no file name for `%sinclude'"), noerror ? "-" : "");
-	      continue;
-	    }
+            continue;
 
 	  /* Parse the list of file names.  */
 	  p2 = p;
