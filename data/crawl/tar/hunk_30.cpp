    includes all the user.*, security.*, system.*, etc. available domains */
 void
 xattrs_xattrs_get (int parentfd, char const *file_name,
-		   struct tar_stat_info *st, int fd)
+                   struct tar_stat_info *st, int fd)
 {
   if (xattrs_option > 0)
     {
 #ifndef HAVE_XATTRS
       static int done = 0;
       if (!done)
-	WARN ((0, 0, _("XATTR support is not available")));
+        WARN ((0, 0, _("XATTR support is not available")));
       done = 1;
 #else
-      static ssize_t xsz = 1024;
+      static size_t xsz = 1024;
       static char *xatrs = NULL;
       ssize_t xret = -1;
 
       if (!xatrs)
-	xatrs = xmalloc (xsz);
+	xatrs = x2nrealloc (xatrs, &xsz, 1);
 
       while (((fd == 0) ?
-	      ((xret =
-		llistxattrat (parentfd, file_name, xatrs, xsz)) == -1) :
-	        ((xret = flistxattr (fd, xatrs, xsz)) == -1))
-	     && (errno == ERANGE))
-	{
-	  xsz <<= 1;
-	  xatrs = xrealloc (xatrs, xsz);
-	}
+              ((xret =
+                llistxattrat (parentfd, file_name, xatrs, xsz)) == -1) :
+	      ((xret = flistxattr (fd, xatrs, xsz)) == -1))
+             && (errno == ERANGE))
+        {
+	  xatrs = x2nrealloc (xatrs, &xsz, 1);
+        }
 
       if (xret == -1)
-	call_arg_warn ((fd == 0) ? "llistxattrat" : "flistxattr", file_name);
+        call_arg_warn ((fd == 0) ? "llistxattrat" : "flistxattr", file_name);
       else
-	{
-	  const char *attr = xatrs;
-	  static ssize_t asz = 1024;
-	  static char *val = NULL;
-
-	  if (!val)
-	    val = xmalloc (asz);
-
-	  while (xret > 0)
-	    {
-	      size_t len = strlen (attr);
-	      ssize_t aret = 0;
-
-	      /* Archive all xattrs during creation, decide at extraction time
-	       * which ones are of interest/use for the target filesystem. */
-	      while (((fd == 0)
-		      ? ((aret = lgetxattrat (parentfd, file_name, attr,
-					      val, asz)) == -1)
-		      : ((aret = fgetxattr (fd, attr, val, asz)) == -1))
-		     && (errno == ERANGE))
-		{
-		  asz <<= 1;
-		  val = xrealloc (val, asz);
-		}
-
-	      if (aret != -1)
-		xheader_xattr_add (st, attr, val, aret);
-	      else if (errno != ENOATTR)
-		call_arg_warn ((fd == 0) ? "lgetxattrat"
-			       : "fgetxattr", file_name);
-
-	      attr += len + 1;
-	      xret -= len + 1;
-	    }
-	}
+        {
+          const char *attr = xatrs;
+          static size_t asz = 1024;
+          static char *val = NULL;
+
+          if (!val)
+            val = x2nrealloc (val, &asz, 1);
+
+          while (xret > 0)
+            {
+              size_t len = strlen (attr);
+              ssize_t aret = 0;
+
+              /* Archive all xattrs during creation, decide at extraction time
+               * which ones are of interest/use for the target filesystem. */
+              while (((fd == 0)
+                      ? ((aret = lgetxattrat (parentfd, file_name, attr,
+                                              val, asz)) == -1)
+                      : ((aret = fgetxattr (fd, attr, val, asz)) == -1))
+                     && (errno == ERANGE))
+                {
+		  val = x2nrealloc (val, &asz, 1);
+                }
+
+              if (aret != -1)
+                xheader_xattr_add (st, attr, val, aret);
+              else if (errno != ENOATTR)
+                call_arg_warn ((fd == 0) ? "lgetxattrat"
+                               : "fgetxattr", file_name);
+
+              attr += len + 1;
+              xret -= len + 1;
+            }
+        }
 #endif
     }
 }
 
 static void
 xattrs__fd_set (struct tar_stat_info const *st,
-		char const *file_name, char typeflag,
-		const char *attr, const char *ptr, size_t len)
+                char const *file_name, char typeflag,
+                const char *attr, const char *ptr, size_t len)
 {
   if (ptr)
     {
