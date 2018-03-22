   else if (acls_option > 0)
     acl = perms2acl (st->stat.st_mode);
   else
-    return; /* don't call acl functions unless we first hit an ACL, or
-               --acls was passed explicitly */
+    return;	/* don't call acl functions unless we first hit an ACL, or
+		   --acls was passed explicitly */
 
-  if (acl == (acl_t)NULL)
+  if (acl == (acl_t) NULL)
     {
       call_arg_warn ("acl_from_text", file_name);
       return;
