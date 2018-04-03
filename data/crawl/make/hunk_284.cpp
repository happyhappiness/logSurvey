                                   PARSEFS_NOAR);
           free (p);
 
-          /* Load each file and add it to the list "to be rebuilt".  */
+          /* Load each file.  */
           while (files != 0)
             {
               struct nameseq *next = files->next;
               const char *name = files->name;
               struct dep *deps;
+              int r;
+
+              /* Load the file.  0 means failure.  */
+              r = load_file (&ebuf->floc, &name, noerror);
+              if (! r && ! noerror)
+                fatal (&ebuf->floc, _("%s: failed to load"), name);
 
               free_ns (files);
               files = next;
 
-              if (! load_file (&ebuf->floc, &name, noerror) && ! noerror)
-                fatal (&ebuf->floc, _("%s: failed to load"), name);
+              /* Return of -1 means a special load: don't rebuild it.  */
+              if (r == -1)
+                continue;
 
+              /* It succeeded, so add it to the list "to be rebuilt".  */
               deps = alloc_dep ();
               deps->next = read_files;
               read_files = deps;
