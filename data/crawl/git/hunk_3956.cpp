 	return 0;
 }
 
+static int remove_dirs(struct strbuf *path, const char *prefix, int force_flag,
+		int dry_run, int quiet, int *dir_gone)
+{
+	DIR *dir;
+	struct strbuf quoted = STRBUF_INIT;
+	struct dirent *e;
+	int res = 0, ret = 0, gone = 1, original_len = path->len, len, i;
+	unsigned char submodule_head[20];
+	struct string_list dels = STRING_LIST_INIT_DUP;
+
+	*dir_gone = 1;
+
+	if ((force_flag & REMOVE_DIR_KEEP_NESTED_GIT) &&
+			!resolve_gitlink_ref(path->buf, "HEAD", submodule_head)) {
+		if (!quiet) {
+			quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+			printf(dry_run ?  _(msg_would_skip_git_dir) : _(msg_skip_git_dir),
+					quoted.buf);
+		}
+
+		*dir_gone = 0;
+		return 0;
+	}
+
+	dir = opendir(path->buf);
+	if (!dir) {
+		/* an empty dir could be removed even if it is unreadble */
+		res = dry_run ? 0 : rmdir(path->buf);
+		if (res) {
+			quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+			warning(_(msg_warn_remove_failed), quoted.buf);
+			*dir_gone = 0;
+		}
+		return res;
+	}
+
+	if (path->buf[original_len - 1] != '/')
+		strbuf_addch(path, '/');
+
+	len = path->len;
+	while ((e = readdir(dir)) != NULL) {
+		struct stat st;
+		if (is_dot_or_dotdot(e->d_name))
+			continue;
+
+		strbuf_setlen(path, len);
+		strbuf_addstr(path, e->d_name);
+		if (lstat(path->buf, &st))
+			; /* fall thru */
+		else if (S_ISDIR(st.st_mode)) {
+			if (remove_dirs(path, prefix, force_flag, dry_run, quiet, &gone))
+				ret = 1;
+			if (gone) {
+				quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+				string_list_append(&dels, quoted.buf);
+			} else
+				*dir_gone = 0;
+			continue;
+		} else {
+			res = dry_run ? 0 : unlink(path->buf);
+			if (!res) {
+				quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+				string_list_append(&dels, quoted.buf);
+			} else {
+				quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+				warning(_(msg_warn_remove_failed), quoted.buf);
+				*dir_gone = 0;
+				ret = 1;
+			}
+			continue;
+		}
+
+		/* path too long, stat fails, or non-directory still exists */
+		*dir_gone = 0;
+		ret = 1;
+		break;
+	}
+	closedir(dir);
+
+	strbuf_setlen(path, original_len);
+
+	if (*dir_gone) {
+		res = dry_run ? 0 : rmdir(path->buf);
+		if (!res)
+			*dir_gone = 1;
+		else {
+			quote_path_relative(path->buf, strlen(path->buf), &quoted, prefix);
+			warning(_(msg_warn_remove_failed), quoted.buf);
+			*dir_gone = 0;
+			ret = 1;
+		}
+	}
+
+	if (!*dir_gone && !quiet) {
+		for (i = 0; i < dels.nr; i++)
+			printf(dry_run ?  _(msg_would_remove) : _(msg_remove), dels.items[i].string);
+	}
+	string_list_clear(&dels, 0);
+	return ret;
+}
+
 int cmd_clean(int argc, const char **argv, const char *prefix)
 {
-	int i;
-	int show_only = 0, remove_directories = 0, quiet = 0, ignored = 0;
-	int ignored_only = 0, config_set = 0, errors = 0;
+	int i, res;
+	int dry_run = 0, remove_directories = 0, quiet = 0, ignored = 0;
+	int ignored_only = 0, config_set = 0, errors = 0, gone = 1;
 	int rm_flags = REMOVE_DIR_KEEP_NESTED_GIT;
 	struct strbuf directory = STRBUF_INIT;
 	struct dir_struct dir;
