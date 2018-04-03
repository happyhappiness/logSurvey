 	}
 	argv_array_push(out, "GIT_DIR=.git");
 }
+
+/*
+ * Embeds a single submodules git directory into the superprojects git dir,
+ * non recursively.
+ */
+static void relocate_single_git_dir_into_superproject(const char *prefix,
+						      const char *path)
+{
+	char *old_git_dir = NULL, *real_old_git_dir = NULL, *real_new_git_dir = NULL;
+	const char *new_git_dir;
+	const struct submodule *sub;
+
+	if (submodule_uses_worktrees(path))
+		die(_("relocate_gitdir for submodule '%s' with "
+		      "more than one worktree not supported"), path);
+
+	old_git_dir = xstrfmt("%s/.git", path);
+	if (read_gitfile(old_git_dir))
+		/* If it is an actual gitfile, it doesn't need migration. */
+		return;
+
+	real_old_git_dir = xstrdup(real_path(old_git_dir));
+
+	sub = submodule_from_path(null_sha1, path);
+	if (!sub)
+		die(_("could not lookup name for submodule '%s'"), path);
+
+	new_git_dir = git_path("modules/%s", sub->name);
+	if (safe_create_leading_directories_const(new_git_dir) < 0)
+		die(_("could not create directory '%s'"), new_git_dir);
+	real_new_git_dir = xstrdup(real_path(new_git_dir));
+
+	if (!prefix)
+		prefix = get_super_prefix();
+
+	fprintf(stderr, _("Migrating git directory of '%s%s' from\n'%s' to\n'%s'\n"),
+		prefix ? prefix : "", path,
+		real_old_git_dir, real_new_git_dir);
+
+	relocate_gitdir(path, real_old_git_dir, real_new_git_dir);
+
+	free(old_git_dir);
+	free(real_old_git_dir);
+	free(real_new_git_dir);
+}
+
+/*
+ * Migrate the git directory of the submodule given by path from
+ * having its git directory within the working tree to the git dir nested
+ * in its superprojects git dir under modules/.
+ */
+void absorb_git_dir_into_superproject(const char *prefix,
+				      const char *path,
+				      unsigned flags)
+{
+	const char *sub_git_dir, *v;
+	char *real_sub_git_dir = NULL, *real_common_git_dir = NULL;
+	struct strbuf gitdir = STRBUF_INIT;
+
+	strbuf_addf(&gitdir, "%s/.git", path);
+	sub_git_dir = resolve_gitdir(gitdir.buf);
+
+	/* Not populated? */
+	if (!sub_git_dir)
+		goto out;
+
+	/* Is it already absorbed into the superprojects git dir? */
+	real_sub_git_dir = xstrdup(real_path(sub_git_dir));
+	real_common_git_dir = xstrdup(real_path(get_git_common_dir()));
+	if (!skip_prefix(real_sub_git_dir, real_common_git_dir, &v))
+		relocate_single_git_dir_into_superproject(prefix, path);
+
+	if (flags & ABSORB_GITDIR_RECURSE_SUBMODULES) {
+		struct child_process cp = CHILD_PROCESS_INIT;
+		struct strbuf sb = STRBUF_INIT;
+
+		if (flags & ~ABSORB_GITDIR_RECURSE_SUBMODULES)
+			die("BUG: we don't know how to pass the flags down?");
+
+		if (get_super_prefix())
+			strbuf_addstr(&sb, get_super_prefix());
+		strbuf_addstr(&sb, path);
+		strbuf_addch(&sb, '/');
+
+		cp.dir = path;
+		cp.git_cmd = 1;
+		cp.no_stdin = 1;
+		argv_array_pushl(&cp.args, "--super-prefix", sb.buf,
+					   "submodule--helper",
+					   "absorb-git-dirs", NULL);
+		prepare_submodule_repo_env(&cp.env_array);
+		if (run_command(&cp))
+			die(_("could not recurse into submodule '%s'"), path);
+
+		strbuf_release(&sb);
+	}
+
+out:
+	strbuf_release(&gitdir);
+	free(real_sub_git_dir);
+	free(real_common_git_dir);
+}
