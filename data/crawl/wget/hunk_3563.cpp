    ftp_retrieve_glob on each directory entry.  The function knows
    about excluded directories.  */
 static uerr_t
-ftp_retrieve_dirs (struct urlinfo *u, struct fileinfo *f, ccon *con)
+ftp_retrieve_dirs (struct url *u, struct fileinfo *f, ccon *con)
 {
-  char *odir;
-  char *current_container = NULL;
-  int current_length = 0;
+  char *container = NULL;
+  int container_size = 0;
 
   for (; f; f = f->next)
     {
-      int len;
+      int size;
+      char *odir, *newdir;
 
       if (downloaded_exceeds_quota ())
 	break;
       if (f->type != FT_DIRECTORY)
 	continue;
-      odir = u->dir;
-      len = strlen (u->dir) + 1 + strlen (f->name) + 1;
+
       /* Allocate u->dir off stack, but reallocate only if a larger
-         string is needed.  */
-      if (len > current_length)
-	current_container = (char *)alloca (len);
-      u->dir = current_container;
+         string is needed.  It's a pity there's no "realloca" for an
+         item on the bottom of the stack.  */
+      size = strlen (u->dir) + 1 + strlen (f->name) + 1;
+      if (size > container_size)
+	container = (char *)alloca (size);
+      newdir = container;
+
+      odir = u->dir;
       if (*odir == '\0'
 	  || (*odir == '/' && *(odir + 1) == '\0'))
 	/* If ODIR is empty or just "/", simply append f->name to
 	   ODIR.  (In the former case, to preserve u->dir being
 	   relative; in the latter case, to avoid double slash.)  */
-	sprintf (u->dir, "%s%s", odir, f->name);
+	sprintf (newdir, "%s%s", odir, f->name);
       else
 	/* Else, use a separator. */
-	sprintf (u->dir, "%s/%s", odir, f->name);
+	sprintf (newdir, "%s/%s", odir, f->name);
+
       DEBUGP (("Composing new CWD relative to the initial directory.\n"));
-      DEBUGP (("  odir = '%s'\n  f->name = '%s'\n  u->dir = '%s'\n\n",
-	       odir, f->name, u->dir));
-      if (!accdir (u->dir, ALLABS))
+      DEBUGP (("  odir = '%s'\n  f->name = '%s'\n  newdir = '%s'\n\n",
+	       odir, f->name, newdir));
+      if (!accdir (newdir, ALLABS))
 	{
 	  logprintf (LOG_VERBOSE, _("\
-Not descending to `%s' as it is excluded/not-included.\n"), u->dir);
-	  u->dir = odir;
+Not descending to `%s' as it is excluded/not-included.\n"), newdir);
 	  continue;
 	}
+
       con->st &= ~DONE_CWD;
+
+      odir = xstrdup (u->dir);	/* because url_set_dir will free
+				   u->dir. */
+      url_set_dir (u, newdir);
       ftp_retrieve_glob (u, con, GETALL);
+      url_set_dir (u, odir);
+      xfree (odir);
+
       /* Set the time-stamp?  */
-      u->dir = odir;
     }
+
   if (opt.quota && opt.downloaded > opt.quota)
     return QUOTEXC;
   else
