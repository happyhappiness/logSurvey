 
 const char *commit_type = "commit";
 
-static struct cmt_fmt_map {
-	const char *n;
-	size_t cmp_len;
-	enum cmit_fmt v;
-} cmt_fmts[] = {
-	{ "raw",	1,	CMIT_FMT_RAW },
-	{ "medium",	1,	CMIT_FMT_MEDIUM },
-	{ "short",	1,	CMIT_FMT_SHORT },
-	{ "email",	1,	CMIT_FMT_EMAIL },
-	{ "full",	5,	CMIT_FMT_FULL },
-	{ "fuller",	5,	CMIT_FMT_FULLER },
-	{ "oneline",	1,	CMIT_FMT_ONELINE },
-	{ "format:",	7,	CMIT_FMT_USERFORMAT},
-};
-
-static char *user_format;
-
-enum cmit_fmt get_commit_format(const char *arg)
-{
-	int i;
-
-	if (!arg || !*arg)
-		return CMIT_FMT_DEFAULT;
-	if (*arg == '=')
-		arg++;
-	if (!prefixcmp(arg, "format:")) {
-		if (user_format)
-			free(user_format);
-		user_format = xstrdup(arg + 7);
-		return CMIT_FMT_USERFORMAT;
-	}
-	for (i = 0; i < ARRAY_SIZE(cmt_fmts); i++) {
-		if (!strncmp(arg, cmt_fmts[i].n, cmt_fmts[i].cmp_len) &&
-		    !strncmp(arg, cmt_fmts[i].n, strlen(arg)))
-			return cmt_fmts[i].v;
-	}
-
-	die("invalid --pretty format: %s", arg);
-}
-
 static struct commit *check_commit(struct object *obj,
 				   const unsigned char *sha1,
 				   int quiet)
