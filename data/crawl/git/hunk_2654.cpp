 	struct strbuf gitdir = STRBUF_INIT;
 	char *existing = NULL;
 
-	/*
-	 * $GIT_COMMON_DIR/$symref (e.g. HEAD) is practically outside
-	 * $GIT_DIR so resolve_ref_unsafe() won't work (it uses
-	 * git_path). Parse the ref ourselves.
-	 */
-	if (id)
-		strbuf_addf(&path, "%s/worktrees/%s/%s", get_git_common_dir(), id, symref);
-	else
-		strbuf_addf(&path, "%s/%s", get_git_common_dir(), symref);
+	if (!id)
+		die("Missing linked worktree name");
 
-	if (!strbuf_readlink(&sb, path.buf, 0)) {
-		if (!starts_with(sb.buf, "refs/") ||
-		    check_refname_format(sb.buf, 0))
-			goto done;
-	} else if (strbuf_read_file(&sb, path.buf, 0) >= 0 &&
-	    starts_with(sb.buf, "ref:")) {
-		strbuf_remove(&sb, 0, strlen("ref:"));
-		strbuf_trim(&sb);
-	} else
+	strbuf_addf(&path, "%s/worktrees/%s/%s", get_git_common_dir(), id, symref);
+
+	if (parse_ref(path.buf, &sb, NULL) < 0)
 		goto done;
 	if (strcmp(sb.buf, branch))
 		goto done;
-	if (id) {
-		strbuf_reset(&path);
-		strbuf_addf(&path, "%s/worktrees/%s/gitdir", get_git_common_dir(), id);
-		if (strbuf_read_file(&gitdir, path.buf, 0) <= 0)
-			goto done;
-		strbuf_rtrim(&gitdir);
-	} else
-		strbuf_addstr(&gitdir, get_git_common_dir());
+	strbuf_reset(&path);
+	strbuf_addf(&path, "%s/worktrees/%s/gitdir", get_git_common_dir(), id);
+	if (strbuf_read_file(&gitdir, path.buf, 0) <= 0)
+		goto done;
+	strbuf_rtrim(&gitdir);
 	strbuf_strip_suffix(&gitdir, ".git");
 
 	existing = strbuf_detach(&gitdir, NULL);
