       0
     };
 
+  static char *libpatterns = NULL;
+
   char *libname = &(*lib)[2];	/* Name without the `-l'.  */
   FILE_TIMESTAMP mtime;
 
-  /* Buffer to construct possible names in.  */
-  char *buf = xmalloc (sizeof (LIBDIR) + 8 + strlen (libname) + 4 + 2 + 1);
-  char *file, **dp;
+  /* Loop variables for the libpatterns value.  */
+  char *p, *p2;
+  int len;
 
-  /* Look first for `libNAME.a' in the current directory.  */
+  char *file, **dp;
 
-#ifndef _AMIGA
-  sprintf (buf, "lib%s.a", libname);
-#else
-  sprintf (buf, "%s.lib", libname);
-#endif
-  mtime = name_mtime (buf);
-  if (mtime != (FILE_TIMESTAMP) -1)
+  /* If we don't have libpatterns, get it.  */
+  if (!libpatterns)
     {
-      *lib = buf;
-      if (mtime_ptr != 0)
-	*mtime_ptr = mtime;
-      return 1;
-    }
+      int save = warn_undefined_variables_flag;
+      warn_undefined_variables_flag = 0;
 
-  /* Now try VPATH search on that.  */
+      libpatterns = strdup (variable_expand ("$(strip $(.LIBPATTERNS))"));
 
-  file = buf;
-  if (vpath_search (&file, mtime_ptr))
-    {
-      free (buf);
-      *lib = file;
-      return 1;
+      warn_undefined_variables_flag = save;
     }
 
-  /* Now try the standard set of directories.  */
-
-#ifdef  __MSDOS__
-  {
-    /* The default library directory is at ${DJDIR}/lib.  */
-    struct variable *djdir = lookup_variable ("DJDIR", 5);
+  /* Loop through all the patterns in .LIBPATTERNS, and search on each one.  */
+  p2 = libpatterns;
+  while ((p = find_next_token (&p2, &len)) != 0)
+    {
+      static char *buf = NULL;
+      static int buflen = 0;
+      static int libdir_maxlen = -1;
+      char *libbuf = variable_expand ("");
 
-    if (djdir)
+      /* Expand the pattern using LIBNAME as a replacement.  */
       {
-	size_t djdir_len = strlen (djdir->value);
+	char c = p[len];
+	char *p3, *p4;
 
-	if (djdir_len > sizeof(LIBDIR) + 8 + strlen(libname) + 4 + 2)
-	  buf = (char *) xrealloc (djdir_len + 1);
-	sprintf (buf, "%s/lib/lib%s.a", djdir->value, libname);
-	mtime = name_mtime (buf);
-	if (mtime != (FILE_TIMESTAMP) -1)
+	p[len] = '\0';
+	p3 = find_percent (p);
+	if (!p3)
 	  {
-	    *lib = buf;
-	    if (mtime_ptr != 0)
-	      *mtime_ptr = mtime;
-	    return 1;
+	    /* Give a warning if there is no pattern, then remove the
+	       pattern so it's ignored next time.  */
+	    error (NILF, ".LIBPATTERNS element `%s' is not a pattern", p);
+	    for (; len; --len, ++p)
+	      *p = ' ';
+	    *p = c;
+	    continue;
 	  }
+	p4 = variable_buffer_output (libbuf, p, p3-p);
+	p4 = variable_buffer_output (p4, libname, strlen (libname));
+	p4 = variable_buffer_output (p4, p3+1, len - (p3-p));
+	p[len] = c;
       }
-  }
-#endif
 
-  for (dp = dirs; *dp != 0; ++dp)
-    {
-#ifndef _AMIGA
-      sprintf (buf, "%s/lib%s.a", *dp, libname);
-#else
-      sprintf (buf, "%s/%s.lib", *dp, libname);
-#endif
-      mtime = name_mtime (buf);
+      /* Look first for `libNAME.a' in the current directory.  */
+      mtime = name_mtime (libbuf);
       if (mtime != (FILE_TIMESTAMP) -1)
 	{
-	  *lib = buf;
+	  *lib = strdup (libbuf);
 	  if (mtime_ptr != 0)
 	    *mtime_ptr = mtime;
 	  return 1;
 	}
+
+      /* Now try VPATH search on that.  */
+
+      file = libbuf;
+      if (vpath_search (&file, mtime_ptr))
+	{
+	  *lib = file;
+	  return 1;
+	}
+
+      /* Now try the standard set of directories.  */
+
+      if (!buflen)
+	{
+	  for (dp = dirs; *dp != 0; ++dp)
+	    {
+	      int l = strlen (*dp);
+	      if (l > libdir_maxlen)
+		libdir_maxlen = l;
+	    }
+	  buflen = strlen (libbuf);
+	  buf = xmalloc(libdir_maxlen + buflen + 2);
+	}
+      else if (buflen < strlen (libbuf))
+	{
+	  buflen = strlen (libbuf);
+	  buf = xrealloc (buf, libdir_maxlen + buflen + 2);
+	}
+
+      for (dp = dirs; *dp != 0; ++dp)
+	{
+	  sprintf (buf, "%s/%s", *dp, libbuf);
+	  mtime = name_mtime (buf);
+	  if (mtime != (FILE_TIMESTAMP) -1)
+	    {
+	      *lib = strdup (buf);
+	      if (mtime_ptr != 0)
+		*mtime_ptr = mtime;
+	      return 1;
+	    }
+	}
     }
 
-  free (buf);
   return 0;
 }
