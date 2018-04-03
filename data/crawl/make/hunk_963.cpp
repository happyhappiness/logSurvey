   while (0)
 
 struct direct *
-readdir (dfd)
-     DIR * dfd;
+readdir (dir)
+     DIR * dir;
 {
-  static struct direct *dentry;
-  static char resultspec[MAXNAMLEN + 1];
+  struct FAB *dfab = &dir->fab;
+  struct NAM *dnam = (struct NAM *)(dfab->fab$l_nam);
+  struct direct *dentry = &dir->dir;
   int i;
 
-  dentry = (struct direct *) xmalloc (sizeof (struct direct));
-  if (! dentry)
-    {
-      printf ("Error mallocing for direct\n");
-      return (NULL);
-    }
+  memset (dentry, 0, sizeof *dentry);
 
-  dfd->fab$l_nam->nam$l_rsa = resultspec;
-  dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;
+  dnam->nam$l_rsa = dir->d_result;
+  dnam->nam$b_rss = MAXNAMLEN;
 
-  DB (DB_EXTRA, ("."));
+  if (debug_flag)
+    printf (".");
 
-  if (!((i = sys$search (dfd)) & 1))
+  if (!((i = sys$search (dfab)) & 1))
     {
-      DB (DB_EXTRA, ("sys$search failed with %d\n", i));
-      free (dentry);
+      if (debug_flag)
+	printf ("sys$search failed with %d\n", i);
       return (NULL);
     }
 
   dentry->d_off = 0;
-  if (dfd->fab$l_nam->nam$w_fid == 0)
+  if (dnam->nam$w_fid == 0)
     dentry->d_fileno = 1;
   else
-    dentry->d_fileno = dfd->fab$l_nam->nam$w_fid[0]
-      + dfd->fab$l_nam->nam$w_fid[1] << 16;
+    dentry->d_fileno = dnam->nam$w_fid[0] + (dnam->nam$w_fid[1] << 16);
+
   dentry->d_reclen = sizeof (struct direct);
-#if 0
-  if (!strcmp(dfd->fab$l_nam->nam$l_type, ".DIR"))
-    dentry->d_namlen = dfd->fab$l_nam->nam$b_name;
-  else
-#endif
-  dentry->d_namlen = dfd->fab$l_nam->nam$b_name + dfd->fab$l_nam->nam$b_type;
-  strncpy (dentry->d_name, dfd->fab$l_nam->nam$l_name, dentry->d_namlen);
+  dentry->d_namlen = dnam->nam$b_name + dnam->nam$b_type;
+  strncpy (dentry->d_name, dnam->nam$l_name, dentry->d_namlen);
   dentry->d_name[dentry->d_namlen] = '\0';
   uppercasify (dentry->d_name);
-#if 0
-  uvUnFixRCSSeparator(dentry->d_name);
-#endif
 
   return (dentry);
 }
 
-closedir (dfd)
-     DIR *dfd;
+int
+closedir (dir)
+     DIR *dir;
 {
-  if (dfd)
+  if (dir != NULL)
     {
-      if (dfd->fab$l_nam)
-	free (dfd->fab$l_nam->nam$l_esa);
-      free (dfd->fab$l_nam);
-      free (dfd);
+      struct FAB *dfab = &dir->fab;
+      struct NAM *dnam = (struct NAM *)(dfab->fab$l_nam);
+      if (dnam != NULL)
+	free (dnam->nam$l_esa);
+      free (dnam);
+      free (dir);
     }
+
+  return 0;
 }
 #endif /* compiled for OpenVMS prior to V7.x */
 
