               /* Load the file.  0 means failure.  */
               r = load_file (&ebuf->floc, &name, noerror);
               if (! r && ! noerror)
-                fatal (&ebuf->floc, _("%s: failed to load"), name);
+                OS (fatal, &ebuf->floc, _("%s: failed to load"), name);
 
               free_ns (files);
               files = next;
