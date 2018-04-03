 	return 0;
 }
 
-static int should_setup_rebase(const struct tracking *tracking)
+static int should_setup_rebase(const char *origin)
 {
 	switch (autorebase) {
 	case AUTOREBASE_NEVER:
 		return 0;
 	case AUTOREBASE_LOCAL:
-		return tracking->remote == NULL;
+		return origin == NULL;
 	case AUTOREBASE_REMOTE:
-		return tracking->remote != NULL;
+		return origin != NULL;
 	case AUTOREBASE_ALWAYS:
 		return 1;
 	}
 	return 0;
 }
 
+void install_branch_config(int flag, const char *local, const char *origin, const char *remote)
+{
+	struct strbuf key = STRBUF_INIT;
+	int rebasing = should_setup_rebase(origin);
+
+	strbuf_addf(&key, "branch.%s.remote", local);
+	git_config_set(key.buf, origin ? origin : ".");
+
+	strbuf_reset(&key);
+	strbuf_addf(&key, "branch.%s.merge", local);
+	git_config_set(key.buf, remote);
+
+	if (rebasing) {
+		strbuf_reset(&key);
+		strbuf_addf(&key, "branch.%s.rebase", local);
+		git_config_set(key.buf, "true");
+	}
+
+	if (flag & BRANCH_CONFIG_VERBOSE)
+		printf("Branch %s set up to track %s branch %s %s.\n",
+		       local,
+		       origin ? "remote" : "local",
+		       remote,
+		       rebasing ? "by rebasing" : "by merging");
+	strbuf_release(&key);
+}
+
 /*
  * This is called when new_ref is branched off of orig_ref, and tries
  * to infer the settings for branch.<new_ref>.{remote,merge} from the
