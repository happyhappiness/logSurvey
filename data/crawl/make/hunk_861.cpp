 	  construct_vpath_list (pattern, p);
 	  if (pattern != 0)
 	    free (pattern);
+
+          goto rule_complete;
 	}
-      else if (word1eq ("include", 7) || word1eq ("-include", 8)
-	       || word1eq ("sinclude", 8))
+
+      if (word1eq ("include") || word1eq ("-include") || word1eq ("sinclude"))
 	{
 	  /* We have found an `include' line specifying a nested
 	     makefile to be read at this point.  */
-	  struct conditionals *save, new_conditionals;
+	  struct conditionals *save;
+          struct conditionals new_conditionals;
 	  struct nameseq *files;
 	  /* "-include" (vs "include") says no error if the file does not
 	     exist.  "sinclude" is an alias for this from SGI.  */
-	  int noerror = p[0] != 'i';
+	  int noerror = (p[0] != 'i');
 
-	  p = allocated_variable_expand (next_token (p + (noerror ? 8 : 7)));
+	  p = allocated_variable_expand (p2);
 	  if (*p == '\0')
 	    {
-	      error (&fileinfo,
+	      error (fstart,
                      _("no file name for `%sinclude'"), noerror ? "-" : "");
 	      continue;
 	    }
