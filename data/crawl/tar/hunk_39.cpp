   struct xattrs_mask_map excl;
 } xattrs_setup;
 
+/* disable posix acls when problem found in gnulib script m4/acl.m4 */
+#if ! USE_ACL
+# undef HAVE_POSIX_ACLS
+#endif
+
+#ifdef HAVE_POSIX_ACLS
+# include "acl.h"
+# include <sys/acl.h>
+#endif
+
+#ifdef HAVE_POSIX_ACLS
+
+/* acl-at wrappers, TODO: move to gnulib in future? */
+acl_t acl_get_file_at (int dirfd, const char *file, acl_type_t type);
+int acl_set_file_at (int dirfd, const char *file, acl_type_t type, acl_t acl);
+int file_has_acl_at (int dirfd, char const *, struct stat const *);
+
+/* acl_get_file_at */
+#define AT_FUNC_NAME acl_get_file_at
+#define AT_FUNC_RESULT acl_t
+#define AT_FUNC_FAIL (acl_t)NULL
+#define AT_FUNC_F1 acl_get_file
+#define AT_FUNC_POST_FILE_PARAM_DECLS   , acl_type_t type
+#define AT_FUNC_POST_FILE_ARGS          , type
+#include "at-func.c"
+#undef AT_FUNC_NAME
+#undef AT_FUNC_F1
+#undef AT_FUNC_RESULT
+#undef AT_FUNC_FAIL
+#undef AT_FUNC_POST_FILE_PARAM_DECLS
+#undef AT_FUNC_POST_FILE_ARGS
+
+/* acl_set_file_at */
+#define AT_FUNC_NAME acl_set_file_at
+#define AT_FUNC_F1 acl_set_file
+#define AT_FUNC_POST_FILE_PARAM_DECLS   , acl_type_t type, acl_t acl
+#define AT_FUNC_POST_FILE_ARGS          , type, acl
+#include "at-func.c"
+#undef AT_FUNC_NAME
+#undef AT_FUNC_F1
+#undef AT_FUNC_POST_FILE_PARAM_DECLS
+#undef AT_FUNC_POST_FILE_ARGS
+
+/* gnulib file_has_acl_at */
+#define AT_FUNC_NAME file_has_acl_at
+#define AT_FUNC_F1 file_has_acl
+#define AT_FUNC_POST_FILE_PARAM_DECLS   , struct stat const *st
+#define AT_FUNC_POST_FILE_ARGS          , st
+#include "at-func.c"
+#undef AT_FUNC_NAME
+#undef AT_FUNC_F1
+#undef AT_FUNC_POST_FILE_PARAM_DECLS
+#undef AT_FUNC_POST_FILE_ARGS
+
+/* convert unix permissions into an ACL ... needed due to "default" ACLs */
+static acl_t perms2acl (int perms)
+{
+  char val[] = "user::---,group::---,other::---";
+  /*            0123456789 123456789 123456789 123456789 */
+
+   /* user */
+  if (perms & 0400) val[ 6] = 'r';
+  if (perms & 0200) val[ 7] = 'w';
+  if (perms & 0100) val[ 8] = 'x';
+
+  /* group */
+  if (perms & 0040) val[17] = 'r';
+  if (perms & 0020) val[18] = 'w';
+  if (perms & 0010) val[19] = 'x';
+
+  /* other */
+  if (perms & 0004) val[28] = 'r';
+  if (perms & 0002) val[29] = 'w';
+  if (perms & 0001) val[30] = 'x';
+
+  return (acl_from_text (val));
+}
+
+static char *skip_to_ext_fields (char *ptr)
+{
+  ptr += strcspn (ptr, ":,\n"); /* skip tag name. Ie. user/group/default/mask */
+
+  if (*ptr != ':')
+    return (ptr); /* error? no user/group field */
+  ++ptr;
+
+  ptr += strcspn (ptr, ":,\n"); /* skip user/group name */
+
+  if (*ptr != ':')
+    return (ptr); /* error? no perms field */
+  ++ptr;
+
+  ptr += strcspn (ptr, ":,\n"); /* skip perms */
+
+  if (*ptr != ':')
+    return (ptr); /* no extra fields */
+
+  return (ptr);
+}
+
+/* The POSIX draft allows extra fields after the three main ones. Star
+   uses this to add a fourth field for user/group which is the numeric ID.
+   We just skip all extra fields atm. */
+static const char *fixup_extra_acl_fields (const char *ptr)
+{
+  char *src = (char *)ptr;
+  char *dst = (char *)ptr;
+
+  while (*src)
+    {
+      const char *old = src;
+      size_t len = 0;
+
+      src = skip_to_ext_fields (src);
+      len = src - old;
+      if (old != dst) memmove (dst, old, len);
+      dst += len;
+
+      if (*src == ':') /* We have extra fields, skip them all */
+        src += strcspn (src, "\n,");
+
+      if ((*src == '\n') || (*src == ','))
+        *dst++ = *src++; /* also done when dst == src, but that's ok */
+    }
+  if (src != dst)
+    *dst = 0;
+
+  return ptr;
+}
+
+static void xattrs__acls_set (struct tar_stat_info const *st,
+                              char const *file_name, int type,
+                              const char *ptr, size_t len, bool def)
+{ /* "system.posix_acl_access" */
+  acl_t acl;
+
+  if (ptr)
+    {
+      /* assert (strlen (ptr) == len); */
+      ptr = fixup_extra_acl_fields (ptr);
+
+      acl = acl_from_text (ptr);
+      acls_option = 1;
+    }
+  else if (acls_option > 0)
+    acl = perms2acl (st->stat.st_mode);
+  else
+    return; /* don't call acl functions unless we first hit an ACL, or
+               --acls was passed explicitly */
+
+  if (acl == (acl_t)NULL)
+    {
+      call_arg_warn ("acl_from_text", file_name);
+      return;
+    }
+
+  if (acl_set_file_at (chdir_fd, file_name, type, acl) == -1)
+    /* warn even if filesystem does not support acls */
+    WARNOPT (WARN_XATTR_WRITE, (0, errno,
+        _("acl_set_file_at: Cannot set POSIX ACLs for file '%s'"), file_name));
+
+  acl_free (acl);
+}
+
+static void xattrs__acls_get_a (int parentfd, const char *file_name,
+                                struct tar_stat_info *st,
+                                char **ret_ptr, size_t *ret_len)
+{ /* "system.posix_acl_access" */
+  char *val = NULL;
+  ssize_t len;
+  acl_t acl;
+
+  if ((acl = acl_get_file_at (parentfd, file_name, ACL_TYPE_ACCESS))
+           == (acl_t)NULL)
+    {
+      if (errno != ENOTSUP)
+        call_arg_warn ("acl_get_file_at", file_name);
+      return;
+    }
+
+  val = acl_to_text (acl, &len);
+  acl_free (acl);
+
+  if (val == NULL)
+    {
+      call_arg_warn ("acl_to_text", file_name);
+      return;
+    }
+
+  *ret_ptr = xstrdup (val);
+  *ret_len = len;
+
+  acl_free (val);
+}
+
+static void xattrs__acls_get_d (int parentfd, char const *file_name,
+                                struct tar_stat_info *st,
+                                char **ret_ptr, size_t *ret_len)
+{ /* "system.posix_acl_default" */
+  char *val = NULL;
+  ssize_t len;
+  acl_t acl;
+
+  if ((acl = acl_get_file_at (parentfd, file_name, ACL_TYPE_DEFAULT))
+      == (acl_t)NULL)
+    {
+      if (errno != ENOTSUP)
+        call_arg_warn ("acl_get_file_at", file_name);
+      return;
+    }
+
+  val = acl_to_text (acl, &len);
+  acl_free (acl);
+
+  if (val == NULL)
+    {
+      call_arg_warn ("acl_to_text", file_name);
+      return;
+    }
+
+  *ret_ptr = xstrdup (val);
+  *ret_len = len;
+
+  acl_free (val);
+}
+#endif /* HAVE_POSIX_ACLS */
+
+static void acls_one_line (const char *prefix, char delim,
+                           const char *aclstring, size_t len)
+{
+  /* support both long and short text representation of posix acls */
+  struct obstack stk;
+  obstack_init (&stk);
+  int pref_len = strlen (prefix);
+  const char *oldstring = aclstring;
+
+  if (!aclstring || !len)
+    return;
+
+  int pos = 0;
+  while (pos <= len)
+    {
+      int move = strcspn (aclstring, ",\n");
+      if (!move)
+        break;
+
+      if (oldstring != aclstring)
+        obstack_1grow (&stk, delim);
+
+      obstack_grow (&stk, prefix, pref_len);
+      obstack_grow (&stk, aclstring, move);
+
+      aclstring += move + 1;
+    }
+
+  obstack_1grow (&stk, '\0');
+  const char *toprint = obstack_finish (&stk);
+
+  fprintf (stdlis, "%s", toprint);
+
+  obstack_free (&stk, NULL);
+}
+
+void xattrs_acls_get (int parentfd, char const *file_name,
+                     struct tar_stat_info *st, int fd, int xisfile)
+{
+  if (acls_option > 0)
+    {
+#ifndef HAVE_POSIX_ACLS
+      static int done = 0;
+      if (!done)
+          WARN ((0, 0, _("POSIX ACL support is not available")));
+      done = 1;
+#else
+      int err = file_has_acl_at (parentfd, file_name, &st->stat);
+      if (err == 0)
+        return;
+      if (err == -1)
+        {
+          call_arg_warn ("file_has_acl_at", file_name);
+          return;
+        }
+
+      xattrs__acls_get_a (parentfd, file_name, st,
+                          &st->acls_a_ptr, &st->acls_a_len);
+      if (!xisfile)
+        xattrs__acls_get_d (parentfd, file_name, st,
+                            &st->acls_d_ptr, &st->acls_d_len);
+#endif
+    }
+}
+
+void xattrs_acls_set (struct tar_stat_info const *st,
+                     char const *file_name, char typeflag)
+{
+  if ((acls_option > 0) && (typeflag != SYMTYPE))
+    {
+#ifndef HAVE_POSIX_ACLS
+      static int done = 0;
+      if (!done)
+        WARN ((0, 0, _("POSIX ACL support is not available")));
+      done = 1;
+#else
+      xattrs__acls_set (st, file_name, ACL_TYPE_ACCESS,
+                        st->acls_a_ptr, st->acls_a_len, false);
+      if ((typeflag == DIRTYPE) || (typeflag == GNUTYPE_DUMPDIR))
+        xattrs__acls_set (st, file_name, ACL_TYPE_DEFAULT,
+                          st->acls_d_ptr, st->acls_d_len, true);
+#endif
+    }
+}
+
 static void mask_map_realloc (struct xattrs_mask_map *map)
 {
   if (map->size == 0)
