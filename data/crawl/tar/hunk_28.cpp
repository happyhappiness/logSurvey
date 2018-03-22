   acl_free (val);
 }
 
+/* "system.posix_acl_default" */
 static void
 xattrs__acls_get_d (int parentfd, char const *file_name,
-		    struct tar_stat_info *st,
-		    char **ret_ptr, size_t * ret_len)
-{				/* "system.posix_acl_default" */
+                    struct tar_stat_info *st,
+                    char **ret_ptr, size_t * ret_len)
+{         
   char *val = NULL;
   ssize_t len;
   acl_t acl;
 
-  if ((acl = acl_get_file_at (parentfd, file_name, ACL_TYPE_DEFAULT))
-      == (acl_t) NULL)
+  if (!(acl = acl_get_file_at (parentfd, file_name, ACL_TYPE_DEFAULT)))
     {
       if (errno != ENOTSUP)
-	call_arg_warn ("acl_get_file_at", file_name);
+        call_arg_warn ("acl_get_file_at", file_name);
       return;
     }
 
   val = acl_to_text (acl, &len);
   acl_free (acl);
 
-  if (val == NULL)
+  if (!val)
     {
       call_arg_warn ("acl_to_text", file_name);
       return;
