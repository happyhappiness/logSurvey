 /* Return the directory listing in a reusable format.  The directory
    is specifed in u->dir.  */
 uerr_t
-ftp_get_listing (struct urlinfo *u, ccon *con, struct fileinfo **f)
+ftp_get_listing (struct url *u, ccon *con, struct fileinfo **f)
 {
   uerr_t err;
-  char *olocal = u->local;
-  char *list_filename, *ofile;
+  char *uf;			/* url file name */
+  char *lf;			/* list file name */
+  char *old_target = con->target;
 
   con->st &= ~ON_YOUR_OWN;
   con->cmd |= (DO_LIST | LEAVE_PENDING);
   con->cmd &= ~DO_RETR;
-  /* Get the listing filename.  */
-  ofile = u->file;
-  u->file = LIST_FILENAME;
-  list_filename = url_filename (u);
-  u->file = ofile;
-  u->local = list_filename;
-  DEBUGP ((_("Using `%s' as listing tmp file.\n"), list_filename));
+
+  /* Find the listing file name.  We do it by taking the file name of
+     the URL and replacing the last component with the listing file
+     name.  */
+  uf = url_filename (u);
+  lf = file_merge (uf, LIST_FILENAME);
+  xfree (uf);
+  DEBUGP ((_("Using `%s' as listing tmp file.\n"), lf));
+
+  con->target = lf;
   err = ftp_loop_internal (u, NULL, con);
-  u->local = olocal;
+  con->target = old_target;
+
   if (err == RETROK)
-    *f = ftp_parse_ls (list_filename, con->rs);
+    *f = ftp_parse_ls (lf, con->rs);
   else
     *f = NULL;
   if (opt.remove_listing)
     {
-      if (unlink (list_filename))
+      if (unlink (lf))
 	logprintf (LOG_NOTQUIET, "unlink: %s\n", strerror (errno));
       else
-	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), list_filename);
+	logprintf (LOG_VERBOSE, _("Removed `%s'.\n"), lf);
     }
-  xfree (list_filename);
+  xfree (lf);
   con->cmd &= ~DO_LIST;
   return err;
 }
 
-static uerr_t ftp_retrieve_dirs PARAMS ((struct urlinfo *, struct fileinfo *,
+static uerr_t ftp_retrieve_dirs PARAMS ((struct url *, struct fileinfo *,
 					 ccon *));
-static uerr_t ftp_retrieve_glob PARAMS ((struct urlinfo *, ccon *, int));
+static uerr_t ftp_retrieve_glob PARAMS ((struct url *, ccon *, int));
 static struct fileinfo *delelement PARAMS ((struct fileinfo *,
 					    struct fileinfo **));
 static void freefileinfo PARAMS ((struct fileinfo *f));
