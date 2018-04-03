             }
         }
 
-      if (file 
-          && (opt.delete_after 
+      if (file
+          && (opt.delete_after
               || opt.spider /* opt.recursive is implicitely true */
               || !acceptable (file)))
         {
           /* Either --delete-after was specified, or we loaded this
-             (otherwise unneeded because of --spider or rejected by -R) 
-             HTML file just to harvest its hyperlinks -- in either case, 
+             (otherwise unneeded because of --spider or rejected by -R)
+             HTML file just to harvest its hyperlinks -- in either case,
              delete the local file. */
           DEBUGP (("Removing file due to %s in recursive_retrieve():\n",
                    opt.delete_after ? "--delete-after" :
-                   (opt.spider ? "--spider" : 
+                   (opt.spider ? "--spider" :
                     "recursive rejection criteria")));
           logprintf (LOG_VERBOSE,
                      (opt.delete_after || opt.spider
