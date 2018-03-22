       int ret = -1;
 
       if (typeflag != SYMTYPE)
-        ret = setxattrat (chdir_fd, file_name, attr, ptr, len, 0);
+	ret = setxattrat (chdir_fd, file_name, attr, ptr, len, 0);
       else
-        {
-          sysname = "lsetxattr";
-          ret = lsetxattrat (chdir_fd, file_name, attr, ptr, len, 0);
-        }
+	{
+	  sysname = "lsetxattr";
+	  ret = lsetxattrat (chdir_fd, file_name, attr, ptr, len, 0);
+	}
 
       if (ret == -1)
-        WARNOPT (WARN_XATTR_WRITE, (0, errno,
-            _("%s: Cannot set '%s' extended attribute for file '%s'"),
-            sysname, attr, file_name));
+	WARNOPT (WARN_XATTR_WRITE,
+		 (0, errno,
+		  _("%s: Cannot set '%s' extended attribute for file '%s'"),
+		  sysname, attr, file_name));
     }
 }
 
 /* lgetfileconat is called against FILE_NAME iff the FD parameter is set to
    zero, otherwise the fgetfileconat is used against correct file descriptor */
-void xattrs_selinux_get (int parentfd, char const *file_name,
-                         struct tar_stat_info *st,  int fd)
+void
+xattrs_selinux_get (int parentfd, char const *file_name,
+		    struct tar_stat_info *st, int fd)
 {
   if (selinux_context_option > 0)
     {
 #if HAVE_SELINUX_SELINUX_H != 1
       static int done = 0;
       if (!done)
-        WARN ((0, 0, _("SELinux support is not available")));
+	WARN ((0, 0, _("SELinux support is not available")));
       done = 1;
 #else
       int result = (fd ? fgetfilecon (fd, &st->cntx_name)
-                       : lgetfileconat (parentfd, file_name, &st->cntx_name));
+		    : lgetfileconat (parentfd, file_name, &st->cntx_name));
 
       if (result == -1 && errno != ENODATA && errno != ENOTSUP)
-        call_arg_warn (fd ? "fgetfilecon" : "lgetfileconat", file_name);
+	call_arg_warn (fd ? "fgetfilecon" : "lgetfileconat", file_name);
 #endif
     }
 }
 
-void xattrs_selinux_set (struct tar_stat_info const *st,
-                         char const *file_name, char typeflag)
+void
+xattrs_selinux_set (struct tar_stat_info const *st,
+		    char const *file_name, char typeflag)
 {
   if (selinux_context_option > 0)
     {
 #if HAVE_SELINUX_SELINUX_H != 1
       static int done = 0;
       if (!done)
-        WARN ((0, 0, _("SELinux support is not available")));
+	WARN ((0, 0, _("SELinux support is not available")));
       done = 1;
 #else
       const char *sysname = "setfilecon";
       int ret;
 
       if (!st->cntx_name)
-        return;
+	return;
 
       if (typeflag != SYMTYPE)
-        {
-          ret = setfileconat (chdir_fd, file_name, st->cntx_name);
-          sysname = "setfileconat";
-        }
+	{
+	  ret = setfileconat (chdir_fd, file_name, st->cntx_name);
+	  sysname = "setfileconat";
+	}
       else
-        {
-          ret = lsetfileconat (chdir_fd, file_name, st->cntx_name);
-          sysname = "lsetfileconat";
-        }
+	{
+	  ret = lsetfileconat (chdir_fd, file_name, st->cntx_name);
+	  sysname = "lsetfileconat";
+	}
 
       if (ret == -1)
-        WARNOPT (WARN_XATTR_WRITE, (0, errno,
-            _("%s: Cannot set SELinux context for file '%s'"), sysname,
-            file_name));
+	WARNOPT (WARN_XATTR_WRITE,
+		 (0, errno,
+		  _("%s: Cannot set SELinux context for file '%s'"),
+		  sysname, file_name));
 #endif
     }
 }
 
-static bool xattrs_matches_mask (const char *kw, struct xattrs_mask_map *mm)
+static bool
+xattrs_matches_mask (const char *kw, struct xattrs_mask_map *mm)
 {
   int i;
 
