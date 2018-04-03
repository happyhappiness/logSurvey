   uerr_t err;
   struct stat st;
 
-  if (!u->local)
-    u->local = url_filename (u);
+  if (!con->target)
+    con->target = url_filename (u);
 
-  if (opt.noclobber && file_exists_p (u->local))
+  if (opt.noclobber && file_exists_p (con->target))
     {
       logprintf (LOG_VERBOSE,
-		 _("File `%s' already there, not retrieving.\n"), u->local);
+		 _("File `%s' already there, not retrieving.\n"), con->target);
       /* If the file is there, we suppose it's retrieved OK.  */
       return RETROK;
     }
 
   /* Remove it if it's a link.  */
-  remove_link (u->local);
+  remove_link (con->target);
   if (!opt.output_document)
-    locf = u->local;
+    locf = con->target;
   else
     locf = opt.output_document;
 
