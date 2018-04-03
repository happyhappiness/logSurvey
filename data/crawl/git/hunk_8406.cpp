 	expand_refspecs();
 }
 
-static int get_remotes_uri(const char *repo, const char *uri[MAX_URI])
-{
-	int n = 0;
-	FILE *f = fopen(git_path("remotes/%s", repo), "r");
-	int has_explicit_refspec = refspec_nr || all || tags;
-
-	if (!f)
-		return -1;
-	while (fgets(buffer, BUF_SIZE, f)) {
-		int is_refspec;
-		char *s, *p;
-
-		if (!prefixcmp(buffer, "URL:")) {
-			is_refspec = 0;
-			s = buffer + 4;
-		} else if (!prefixcmp(buffer, "Push:")) {
-			is_refspec = 1;
-			s = buffer + 5;
-		} else
-			continue;
-
-		/* Remove whitespace at the head.. */
-		while (isspace(*s))
-			s++;
-		if (!*s)
-			continue;
-
-		/* ..and at the end */
-		p = s + strlen(s);
-		while (isspace(p[-1]))
-			*--p = 0;
-
-		if (!is_refspec) {
-			if (n < MAX_URI)
-				uri[n++] = xstrdup(s);
-			else
-				error("more than %d URL's specified, ignoring the rest", MAX_URI);
-		}
-		else if (is_refspec && !has_explicit_refspec) {
-			if (!wildcard_ref(s))
-				add_refspec(xstrdup(s));
-		}
-	}
-	fclose(f);
-	if (!n)
-		die("remote '%s' has no URL", repo);
-	return n;
-}
-
-static const char **config_uri;
-static const char *config_repo;
-static int config_repo_len;
-static int config_current_uri;
-static int config_get_refspecs;
-static int config_get_receivepack;
-
-static int get_remote_config(const char* key, const char* value)
-{
-	if (!prefixcmp(key, "remote.") &&
-	    !strncmp(key + 7, config_repo, config_repo_len)) {
-		if (!strcmp(key + 7 + config_repo_len, ".url")) {
-			if (config_current_uri < MAX_URI)
-				config_uri[config_current_uri++] = xstrdup(value);
-			else
-				error("more than %d URL's specified, ignoring the rest", MAX_URI);
-		}
-		else if (config_get_refspecs &&
-			 !strcmp(key + 7 + config_repo_len, ".push")) {
-			if (!wildcard_ref(value))
-				add_refspec(xstrdup(value));
-		}
-		else if (config_get_receivepack &&
-			 !strcmp(key + 7 + config_repo_len, ".receivepack")) {
-			if (!receivepack) {
-				char *rp = xmalloc(strlen(value) + 16);
-				sprintf(rp, "--receive-pack=%s", value);
-				receivepack = rp;
-			} else
-				error("more than one receivepack given, using the first");
-		}
-	}
-	return 0;
-}
-
-static int get_config_remotes_uri(const char *repo, const char *uri[MAX_URI])
-{
-	config_repo_len = strlen(repo);
-	config_repo = repo;
-	config_current_uri = 0;
-	config_uri = uri;
-	config_get_refspecs = !(refspec_nr || all || tags);
-	config_get_receivepack = (receivepack == NULL);
-
-	git_config(get_remote_config);
-	return config_current_uri;
-}
-
-static int get_branches_uri(const char *repo, const char *uri[MAX_URI])
-{
-	const char *slash = strchr(repo, '/');
-	int n = slash ? slash - repo : 1000;
-	FILE *f = fopen(git_path("branches/%.*s", n, repo), "r");
-	char *s, *p;
-	int len;
-
-	if (!f)
-		return 0;
-	s = fgets(buffer, BUF_SIZE, f);
-	fclose(f);
-	if (!s)
-		return 0;
-	while (isspace(*s))
-		s++;
-	if (!*s)
-		return 0;
-	p = s + strlen(s);
-	while (isspace(p[-1]))
-		*--p = 0;
-	len = p - s;
-	if (slash)
-		len += strlen(slash);
-	p = xmalloc(len + 1);
-	strcpy(p, s);
-	if (slash)
-		strcat(p, slash);
-	uri[0] = p;
-	return 1;
-}
-
-/*
- * Read remotes and branches file, fill the push target URI
- * list.  If there is no command line refspecs, read Push: lines
- * to set up the *refspec list as well.
- * return the number of push target URIs
- */
-static int read_config(const char *repo, const char *uri[MAX_URI])
-{
-	int n;
-
-	if (*repo != '/') {
-		n = get_remotes_uri(repo, uri);
-		if (n > 0)
-			return n;
-
-		n = get_config_remotes_uri(repo, uri);
-		if (n > 0)
-			return n;
-
-		n = get_branches_uri(repo, uri);
-		if (n > 0)
-			return n;
-	}
-
-	uri[0] = repo;
-	return 1;
-}
-
 static int do_push(const char *repo)
 {
-	const char *uri[MAX_URI];
-	int i, n, errs;
+	int i, errs;
 	int common_argc;
 	const char **argv;
 	int argc;
+	struct remote *remote = remote_get(repo);
 
-	n = read_config(repo, uri);
-	if (n <= 0)
+	if (!remote)
 		die("bad repository '%s'", repo);
 
+	if (remote->receivepack) {
+		char *rp = xmalloc(strlen(remote->receivepack) + 16);
+		sprintf(rp, "--receive-pack=%s", remote->receivepack);
+		receivepack = rp;
+	}
+	if (!refspec && !all && !tags && remote->push_refspec_nr) {
+		for (i = 0; i < remote->push_refspec_nr; i++) {
+			if (!wildcard_ref(remote->push_refspec[i]))
+				add_refspec(remote->push_refspec[i]);
+		}
+	}
+
 	argv = xmalloc((refspec_nr + 10) * sizeof(char *));
 	argv[0] = "dummy-send-pack";
 	argc = 1;
