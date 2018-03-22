   obstack_free (&stk, NULL);
 }
 
-void xattrs_acls_get (int parentfd, char const *file_name,
-                     struct tar_stat_info *st, int fd, int xisfile)
+void
+xattrs_acls_get (int parentfd, char const *file_name,
+		 struct tar_stat_info *st, int fd, int xisfile)
 {
   if (acls_option > 0)
     {
 #ifndef HAVE_POSIX_ACLS
       static int done = 0;
       if (!done)
-          WARN ((0, 0, _("POSIX ACL support is not available")));
+	WARN ((0, 0, _("POSIX ACL support is not available")));
       done = 1;
 #else
       int err = file_has_acl_at (parentfd, file_name, &st->stat);
       if (err == 0)
-        return;
+	return;
       if (err == -1)
-        {
-          call_arg_warn ("file_has_acl_at", file_name);
-          return;
-        }
+	{
+	  call_arg_warn ("file_has_acl_at", file_name);
+	  return;
+	}
 
       xattrs__acls_get_a (parentfd, file_name, st,
-                          &st->acls_a_ptr, &st->acls_a_len);
+			  &st->acls_a_ptr, &st->acls_a_len);
       if (!xisfile)
-        xattrs__acls_get_d (parentfd, file_name, st,
-                            &st->acls_d_ptr, &st->acls_d_len);
+	xattrs__acls_get_d (parentfd, file_name, st,
+			    &st->acls_d_ptr, &st->acls_d_len);
 #endif
     }
 }
 
-void xattrs_acls_set (struct tar_stat_info const *st,
-                     char const *file_name, char typeflag)
+void
+xattrs_acls_set (struct tar_stat_info const *st,
+		 char const *file_name, char typeflag)
 {
   if ((acls_option > 0) && (typeflag != SYMTYPE))
     {
 #ifndef HAVE_POSIX_ACLS
       static int done = 0;
       if (!done)
-        WARN ((0, 0, _("POSIX ACL support is not available")));
+	WARN ((0, 0, _("POSIX ACL support is not available")));
       done = 1;
 #else
       xattrs__acls_set (st, file_name, ACL_TYPE_ACCESS,
-                        st->acls_a_ptr, st->acls_a_len, false);
+			st->acls_a_ptr, st->acls_a_len, false);
       if ((typeflag == DIRTYPE) || (typeflag == GNUTYPE_DUMPDIR))
-        xattrs__acls_set (st, file_name, ACL_TYPE_DEFAULT,
-                          st->acls_d_ptr, st->acls_d_len, true);
+	xattrs__acls_set (st, file_name, ACL_TYPE_DEFAULT,
+			  st->acls_d_ptr, st->acls_d_len, true);
 #endif
     }
 }
 
-static void mask_map_realloc (struct xattrs_mask_map *map)
+static void
+mask_map_realloc (struct xattrs_mask_map *map)
 {
   if (map->size == 0)
     {
