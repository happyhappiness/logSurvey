 	return execv_git_cmd(my_argv);
 }
 
+static int do_cvs_cmd(const char *me, char *arg)
+{
+	const char *cvsserver_argv[3] = {
+		"cvsserver", "server", NULL
+	};
+	const char *oldpath = getenv("PATH");
+	struct strbuf newpath = STRBUF_INIT;
+
+	if (!arg || strcmp(arg, "server"))
+		die("git-cvsserver only handles server: %s", arg);
+
+	strbuf_addstr(&newpath, git_exec_path());
+	strbuf_addch(&newpath, ':');
+	strbuf_addstr(&newpath, oldpath);
+
+	setenv("PATH", strbuf_detach(&newpath, NULL), 1);
+
+	return execv_git_cmd(cvsserver_argv);
+}
+
+
 static struct commands {
 	const char *name;
 	int (*exec)(const char *me, char *arg);
 } cmd_list[] = {
 	{ "git-receive-pack", do_generic_cmd },
 	{ "git-upload-pack", do_generic_cmd },
+	{ "cvs", do_cvs_cmd },
 	{ NULL },
 };
 
