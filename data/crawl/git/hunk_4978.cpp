 		close(fd);
 }
 
+#ifdef NO_POSIX_GOODIES
+
+struct credentials;
+
+static void drop_privileges(struct credentials *cred)
+{
+	/* nothing */
+}
+
+static void daemonize(void)
+{
+	die("--detach not supported on this platform");
+}
+
+static struct credentials *prepare_credentials(const char *user_name,
+    const char *group_name)
+{
+	die("--user not supported on this platform");
+}
+
+#else
+
+struct credentials {
+	struct passwd *pass;
+	gid_t gid;
+};
+
+static void drop_privileges(struct credentials *cred)
+{
+	if (cred && (initgroups(cred->pass->pw_name, cred->gid) ||
+	    setgid (cred->gid) || setuid(cred->pass->pw_uid)))
+		die("cannot drop privileges");
+}
+
+static struct credentials *prepare_credentials(const char *user_name,
+    const char *group_name)
+{
+	static struct credentials c;
+
+	c.pass = getpwnam(user_name);
+	if (!c.pass)
+		die("user not found - %s", user_name);
+
+	if (!group_name)
+		c.gid = c.pass->pw_gid;
+	else {
+		struct group *group = getgrnam(group_name);
+		if (!group)
+			die("group not found - %s", group_name);
+
+		c.gid = group->gr_gid;
+	}
+
+	return &c;
+}
+
 static void daemonize(void)
 {
 	switch (fork()) {
