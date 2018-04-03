 #define get_gecos(struct_passwd) ((struct_passwd)->pw_gecos)
 #endif
 
-static struct passwd *xgetpwuid_self(void)
+static struct passwd *xgetpwuid_self(int *is_bogus)
 {
 	struct passwd *pw;
 
 	errno = 0;
 	pw = getpwuid(getuid());
-	if (!pw)
-		die(_("unable to look up current user in the passwd file: %s"),
-		    errno ? strerror(errno) : _("no such user"));
+	if (!pw) {
+		static struct passwd fallback;
+		fallback.pw_name = "unknown";
+#ifndef NO_GECOS_IN_PWENT
+		fallback.pw_gecos = "Unknown";
+#endif
+		pw = &fallback;
+		if (is_bogus)
+			*is_bogus = 1;
+	}
 	return pw;
 }
 
