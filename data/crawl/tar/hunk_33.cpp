 
   if (acl_set_file_at (chdir_fd, file_name, type, acl) == -1)
     /* warn even if filesystem does not support acls */
-    WARNOPT (WARN_XATTR_WRITE, (0, errno,
-        _("acl_set_file_at: Cannot set POSIX ACLs for file '%s'"), file_name));
+    WARNOPT (WARN_XATTR_WRITE,
+	     (0, errno,
+	      _("acl_set_file_at: Cannot set POSIX ACLs for file '%s'"),
+	      file_name));
 
   acl_free (acl);
 }
 
-static void xattrs__acls_get_a (int parentfd, const char *file_name,
-                                struct tar_stat_info *st,
-                                char **ret_ptr, size_t *ret_len)
+static void
+xattrs__acls_get_a (int parentfd, const char *file_name,
+		    struct tar_stat_info *st,
+		    char **ret_ptr, size_t * ret_len)
 { /* "system.posix_acl_access" */
   char *val = NULL;
   ssize_t len;
   acl_t acl;
 
   if ((acl = acl_get_file_at (parentfd, file_name, ACL_TYPE_ACCESS))
-           == (acl_t)NULL)
+      == (acl_t) NULL)
     {
       if (errno != ENOTSUP)
-        call_arg_warn ("acl_get_file_at", file_name);
+	call_arg_warn ("acl_get_file_at", file_name);
       return;
     }
 
