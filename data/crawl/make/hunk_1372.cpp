 #include <fibdef.h>
 #include "vmsdir.h"
 
-DIR *opendir(char *dspec)
+#if __VMS_VER < 70000000
+
+DIR *
+opendir (dspec)
+     char *dspec;
 {
   static struct FAB *dfab;
   struct NAM *dnam;
   char *searchspec;
 
-  if ((dfab = (struct FAB *)xmalloc(sizeof (struct FAB))) == NULL) {
-    printf("Error mallocing for FAB\n");
-    return(NULL);
-  }
-  if ((dnam = (struct NAM *)xmalloc(sizeof (struct NAM))) == NULL) {
-    printf("Error mallocing for NAM\n");
-    free(dfab);
-    return(NULL);
-  }
-  if ((searchspec = (char *)xmalloc(MAXNAMLEN+1)) == NULL) {
-    printf("Error mallocing for searchspec\n");
-    free(dfab);
-    free(dnam);
-    return(NULL);
-  }
-
-  sprintf(searchspec,"%s*.*;",dspec);
+  dfab = (struct FAB *) xmalloc (sizeof (struct FAB));
+  if (! dfab)
+    {
+      printf ("Error mallocing for FAB\n");
+      return (NULL);
+    }
+
+  dnam = (struct NAM *) xmalloc (sizeof (struct NAM));
+  if (! dnam)
+    {
+      printf ("Error mallocing for NAM\n");
+      free (dfab);
+      return (NULL);
+    }
+
+  searchspec = (char *) xmalloc (MAXNAMLEN + 1);
+  if (! searchspec)
+    {
+      printf ("Error mallocing for searchspec\n");
+      free (dfab);
+      free (dnam);
+      return (NULL);
+    }
+
+  sprintf (searchspec, "%s*.*;", dspec);
 
   *dfab = cc$rms_fab;
   dfab->fab$l_fna = searchspec;
-  dfab->fab$b_fns = strlen(searchspec);
+  dfab->fab$b_fns = strlen (searchspec);
   dfab->fab$l_nam = dnam;
 
   *dnam = cc$rms_nam;
   dnam->nam$l_esa = searchspec;
   dnam->nam$b_ess = MAXNAMLEN;
 
-  if (!(sys$parse(dfab) & 1)) {
-    free(dfab);
-    free(dnam);
-    free(searchspec);
-    return(NULL);
-  }
+  if (! (sys$parse (dfab) & 1))
+    {
+      free (dfab);
+      free (dnam);
+      free (searchspec);
+      return (NULL);
+    }
 
-  return(dfab);
+  return (dfab);
 }
 
-#include <ctype.h>
-#define uppercasify(str) { char *tmp; for(tmp = (str); *tmp != '\0'; tmp++) if(islower(*tmp)) *tmp = toupper(*tmp); }
-
-struct direct *readdir(DIR *dfd)
+#define uppercasify(str) \
+  do \
+    { \
+      char *tmp; \
+      for (tmp = (str); *tmp != '\0'; tmp++) \
+        if (islower (*tmp)) \
+          *tmp = toupper (*tmp); \
+    } \
+  while (0)
+
+struct direct *
+readdir (dfd)
+     DIR * dfd;
 {
   static struct direct *dentry;
-  static char resultspec[MAXNAMLEN+1];
+  static char resultspec[MAXNAMLEN + 1];
   int i;
 
-  if ((dentry = (struct direct *)xmalloc(sizeof (struct direct))) == NULL) {
-    printf("Error mallocing for direct\n");
-    return(NULL);
-  }
+  dentry = (struct direct *) xmalloc (sizeof (struct direct));
+  if (! dentry)
+    {
+      printf ("Error mallocing for direct\n");
+      return (NULL);
+    }
 
   dfd->fab$l_nam->nam$l_rsa = resultspec;
   dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;
 
   if (debug_flag)
-    printf(".");
+    printf (".");
 
-  if (!((i = sys$search(dfd)) & 1)) {
-    if (debug_flag)
-      printf("sys$search failed with %d\n", i);
-    free(dentry);
-    return(NULL);
-  }
+  if (!((i = sys$search (dfd)) & 1))
+    {
+      if (debug_flag)
+	printf ("sys$search failed with %d\n", i);
+      free (dentry);
+      return (NULL);
+    }
 
   dentry->d_off = 0;
   if (dfd->fab$l_nam->nam$w_fid == 0)
     dentry->d_fileno = 1;
-  else dentry->d_fileno = dfd->fab$l_nam->nam$w_fid[0]
-			 +dfd->fab$l_nam->nam$w_fid[1]<<16;
+  else
+    dentry->d_fileno = dfd->fab$l_nam->nam$w_fid[0]
+      + dfd->fab$l_nam->nam$w_fid[1] << 16;
   dentry->d_reclen = sizeof (struct direct);
-/*
-  if (!strcmp(dfd->fab$l_nam->nam$l_type,".DIR"))
+#if 0
+  if (!strcmp(dfd->fab$l_nam->nam$l_type, ".DIR"))
     dentry->d_namlen = dfd->fab$l_nam->nam$b_name;
   else
-*/
-    dentry->d_namlen = dfd->fab$l_nam->nam$b_name+dfd->fab$l_nam->nam$b_type;
-  strncpy(dentry->d_name,dfd->fab$l_nam->nam$l_name,dentry->d_namlen);
+#endif
+  dentry->d_namlen = dfd->fab$l_nam->nam$b_name + dfd->fab$l_nam->nam$b_type;
+  strncpy (dentry->d_name, dfd->fab$l_nam->nam$l_name, dentry->d_namlen);
   dentry->d_name[dentry->d_namlen] = '\0';
-  uppercasify(dentry->d_name);
-/*  uvUnFixRCSSeparator(dentry->d_name);*/
+  uppercasify (dentry->d_name);
+#if 0
+  uvUnFixRCSSeparator(dentry->d_name);
+#endif
 
-  return(dentry);
+  return (dentry);
 }
 
-closedir(DIR *dfd)
+closedir (dfd)
+     DIR *dfd;
 {
-  if (dfd != NULL) {
-    if (dfd->fab$l_nam != NULL)
-      free(dfd->fab$l_nam->nam$l_esa);
-    free(dfd->fab$l_nam);
-    free(dfd);
-  }
+  if (dfd)
+    {
+      if (dfd->fab$l_nam)
+	free (dfd->fab$l_nam->nam$l_esa);
+      free (dfd->fab$l_nam);
+      free (dfd);
+    }
 }
+#endif /* compiled for OpenVMS prior to V7.x */
 
-char *getwd(char *cwd)
+char *
+getwd (cwd)
+     char *cwd;
 {
   static char buf[512];
 
-    if (cwd)
-      return(getcwd(cwd,512));
-    else
-      return(getcwd(buf,512));
+  if (cwd)
+    return (getcwd (cwd, 512));
+  else
+    return (getcwd (buf, 512));
 }
 
 int
