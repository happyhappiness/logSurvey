 
 void warn_on_inaccessible(const char *path)
 {
-	warning(_("unable to access '%s': %s"), path, strerror(errno));
+	warning_errno(_("unable to access '%s'"), path);
 }
 
 static int access_error_is_ok(int err, unsigned flag)