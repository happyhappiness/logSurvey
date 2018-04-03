               free (ap);
             }
           continue;
-	}
+        }
 
       /* Handle the special syntax for vpath.  */
       if (word1eq ("vpath"))
-	{
+        {
           const char *cp;
-	  char *vpat;
-	  unsigned int l;
+          char *vpat;
+          unsigned int l;
 
           /* vpath ends the previous rule.  */
           record_waiting_files ();
 
-	  cp = variable_expand (p2);
-	  p = find_next_token (&cp, &l);
-	  if (p != 0)
-	    {
-	      vpat = xstrndup (p, l);
-	      p = find_next_token (&cp, &l);
-	      /* No searchpath means remove all previous
-		 selective VPATH's with the same pattern.  */
-	    }
-	  else
-	    /* No pattern means remove all previous selective VPATH's.  */
-	    vpat = 0;
-	  construct_vpath_list (vpat, p);
-	  if (vpat != 0)
-	    free (vpat);
+          cp = variable_expand (p2);
+          p = find_next_token (&cp, &l);
+          if (p != 0)
+            {
+              vpat = xstrndup (p, l);
+              p = find_next_token (&cp, &l);
+              /* No searchpath means remove all previous
+                 selective VPATH's with the same pattern.  */
+            }
+          else
+            /* No pattern means remove all previous selective VPATH's.  */
+            vpat = 0;
+          construct_vpath_list (vpat, p);
+          if (vpat != 0)
+            free (vpat);
 
           continue;
-	}
+        }
 
       /* Handle include and variants.  */
       if (word1eq ("include") || word1eq ("-include") || word1eq ("sinclude"))
-	{
-	  /* We have found an 'include' line specifying a nested
-	     makefile to be read at this point.  */
-	  struct conditionals *save;
+        {
+          /* We have found an 'include' line specifying a nested
+             makefile to be read at this point.  */
+          struct conditionals *save;
           struct conditionals new_conditionals;
-	  struct nameseq *files;
-	  /* "-include" (vs "include") says no error if the file does not
-	     exist.  "sinclude" is an alias for this from SGI.  */
-	  int noerror = (p[0] != 'i');
+          struct nameseq *files;
+          /* "-include" (vs "include") says no error if the file does not
+             exist.  "sinclude" is an alias for this from SGI.  */
+          int noerror = (p[0] != 'i');
 
           /* Include ends the previous rule.  */
           record_waiting_files ();
 
-	  p = allocated_variable_expand (p2);
+          p = allocated_variable_expand (p2);
 
           /* If no filenames, it's a no-op.  */
-	  if (*p == '\0')
+          if (*p == '\0')
             {
               free (p);
               continue;
             }
 
-	  /* Parse the list of file names.  Don't expand archive references!  */
-	  p2 = p;
-	  files = PARSE_FILE_SEQ (&p2, struct nameseq, '\0', NULL,
+          /* Parse the list of file names.  Don't expand archive references!  */
+          p2 = p;
+          files = PARSE_FILE_SEQ (&p2, struct nameseq, '\0', NULL,
                                   PARSEFS_NOAR);
-	  free (p);
+          free (p);
 
-	  /* Save the state of conditionals and start
-	     the included makefile with a clean slate.  */
-	  save = install_conditionals (&new_conditionals);
+          /* Save the state of conditionals and start
+             the included makefile with a clean slate.  */
+          save = install_conditionals (&new_conditionals);
 
-	  /* Record the rules that are waiting so they will determine
-	     the default goal before those in the included makefile.  */
-	  record_waiting_files ();
+          /* Record the rules that are waiting so they will determine
+             the default goal before those in the included makefile.  */
+          record_waiting_files ();
 
-	  /* Read each included makefile.  */
-	  while (files != 0)
-	    {
-	      struct nameseq *next = files->next;
-	      const char *name = files->name;
+          /* Read each included makefile.  */
+          while (files != 0)
+            {
+              struct nameseq *next = files->next;
+              const char *name = files->name;
               int r;
 
-	      free_ns (files);
-	      files = next;
+              free_ns (files);
+              files = next;
 
               r = eval_makefile (name,
                                  (RM_INCLUDED | RM_NO_TILDE
                                   | (noerror ? RM_DONTCARE : 0)
                                   | (set_default ? 0 : RM_NO_DEFAULT_GOAL)));
-	      if (!r && !noerror)
+              if (!r && !noerror)
                 error (fstart, "%s: %s", name, strerror (errno));
-	    }
+            }
 
-	  /* Restore conditional state.  */
-	  restore_conditionals (save);
+          /* Restore conditional state.  */
+          restore_conditionals (save);
 
           continue;
-	}
+        }
 
       /* Handle the load operations.  */
       if (word1eq ("load") || word1eq ("-load"))
         {
-	  /* A 'load' line specifies a dynamic object to load.  */
-	  struct nameseq *files;
+          /* A 'load' line specifies a dynamic object to load.  */
+          struct nameseq *files;
           int noerror = (p[0] == '-');
 
           /* Load ends the previous rule.  */
           record_waiting_files ();
 
-	  p = allocated_variable_expand (p2);
+          p = allocated_variable_expand (p2);
 
           /* If no filenames, it's a no-op.  */
-	  if (*p == '\0')
+          if (*p == '\0')
             {
               free (p);
               continue;
             }
 
-	  /* Parse the list of file names.
+          /* Parse the list of file names.
              Don't expand archive references or strip "./"  */
-	  p2 = p;
-	  files = PARSE_FILE_SEQ (&p2, struct nameseq, '\0', NULL,
-                                  PARSEFS_NOAR|PARSEFS_NOSTRIP);
-	  free (p);
+          p2 = p;
+          files = PARSE_FILE_SEQ (&p2, struct nameseq, '\0', NULL,
+                                  PARSEFS_NOAR);
+          free (p);
 
-	  /* Load each file.  */
-	  while (files != 0)
-	    {
-	      struct nameseq *next = files->next;
-	      const char *name = files->name;
+          /* Load each file and add it to the list "to be rebuilt".  */
+          while (files != 0)
+            {
+              struct nameseq *next = files->next;
+              const char *name = files->name;
+              struct dep *deps;
 
-	      free_ns (files);
-	      files = next;
+              free_ns (files);
+              files = next;
 
-              if (! load_file (&ebuf->floc, name, noerror) && ! noerror)
+              if (! load_file (&ebuf->floc, &name, noerror) && ! noerror)
                 fatal (&ebuf->floc, _("%s: failed to load"), name);
-	    }
+
+              deps = alloc_dep ();
+              deps->next = read_files;
+              read_files = deps;
+              deps->file = lookup_file (name);
+              if (deps->file == 0)
+                deps->file = enter_file (name);
+            }
 
           continue;
         }
