 	return git_config_set_multivar(key, tmp->buf, "^$", 0);
 }
 
+static int parse_mirror_opt(const struct option *opt, const char *arg, int not)
+{
+	unsigned *mirror = opt->value;
+	if (not)
+		*mirror = MIRROR_NONE;
+	else if (!arg)
+		*mirror = MIRROR_BOTH;
+	else if (!strcmp(arg, "fetch"))
+		*mirror = MIRROR_FETCH;
+	else if (!strcmp(arg, "push"))
+		*mirror = MIRROR_PUSH;
+	else
+		return error("unknown mirror argument: %s", arg);
+	return 0;
+}
+
 static int add(int argc, const char **argv)
 {
-	int fetch = 0, mirror = 0, fetch_tags = TAGS_DEFAULT;
+	int fetch = 0, fetch_tags = TAGS_DEFAULT;
+	unsigned mirror = MIRROR_NONE;
 	struct string_list track = STRING_LIST_INIT_NODUP;
 	const char *master = NULL;
 	struct remote *remote;
