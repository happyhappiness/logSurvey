 	return 0;
 }
 
+struct rename_info {
+	const char *old;
+	const char *new;
+	struct string_list *remote_branches;
+};
+
+static int read_remote_branches(const char *refname,
+	const unsigned char *sha1, int flags, void *cb_data)
+{
+	struct rename_info *rename = cb_data;
+	struct strbuf buf = STRBUF_INIT;
+	struct string_list_item *item;
+	int flag;
+	unsigned char orig_sha1[20];
+	const char *symref;
+
+	strbuf_addf(&buf, "refs/remotes/%s", rename->old);
+	if(!prefixcmp(refname, buf.buf)) {
+		item = string_list_append(xstrdup(refname), rename->remote_branches);
+		symref = resolve_ref(refname, orig_sha1, 1, &flag);
+		if (flag & REF_ISSYMREF)
+			item->util = xstrdup(symref);
+		else
+			item->util = NULL;
+	}
+
+	return 0;
+}
+
+static int mv(int argc, const char **argv)
+{
+	struct option options[] = {
+		OPT_END()
+	};
+	struct remote *oldremote, *newremote;
+	struct strbuf buf = STRBUF_INIT, buf2 = STRBUF_INIT, buf3 = STRBUF_INIT;
+	struct string_list remote_branches = { NULL, 0, 0, 0 };
+	struct rename_info rename;
+	int i;
+
+	if (argc != 3)
+		usage_with_options(builtin_remote_usage, options);
+
+	rename.old = argv[1];
+	rename.new = argv[2];
+	rename.remote_branches = &remote_branches;
+
+	oldremote = remote_get(rename.old);
+	if (!oldremote)
+		die("No such remote: %s", rename.old);
+
+	newremote = remote_get(rename.new);
+	if (newremote && (newremote->url_nr > 1 || newremote->fetch_refspec_nr))
+		die("remote %s already exists.", rename.new);
+
+	strbuf_addf(&buf, "refs/heads/test:refs/remotes/%s/test", rename.new);
+	if (!valid_fetch_refspec(buf.buf))
+		die("'%s' is not a valid remote name", rename.new);
+
+	strbuf_reset(&buf);
+	strbuf_addf(&buf, "remote.%s", rename.old);
+	strbuf_addf(&buf2, "remote.%s", rename.new);
+	if (git_config_rename_section(buf.buf, buf2.buf) < 1)
+		return error("Could not rename config section '%s' to '%s'",
+				buf.buf, buf2.buf);
+
+	strbuf_reset(&buf);
+	strbuf_addf(&buf, "remote.%s.fetch", rename.new);
+	if (git_config_set_multivar(buf.buf, NULL, NULL, 1))
+		return error("Could not remove config section '%s'", buf.buf);
+	for (i = 0; i < oldremote->fetch_refspec_nr; i++) {
+		char *ptr;
+
+		strbuf_reset(&buf2);
+		strbuf_addstr(&buf2, oldremote->fetch_refspec[i]);
+		ptr = strstr(buf2.buf, rename.old);
+		if (ptr)
+			strbuf_splice(&buf2, ptr-buf2.buf, strlen(rename.old),
+					rename.new, strlen(rename.new));
+		if (git_config_set_multivar(buf.buf, buf2.buf, "^$", 0))
+			return error("Could not append '%s'", buf.buf);
+	}
+
+	read_branches();
+	for (i = 0; i < branch_list.nr; i++) {
+		struct string_list_item *item = branch_list.items + i;
+		struct branch_info *info = item->util;
+		if (info->remote && !strcmp(info->remote, rename.old)) {
+			strbuf_reset(&buf);
+			strbuf_addf(&buf, "branch.%s.remote", item->string);
+			if (git_config_set(buf.buf, rename.new)) {
+				return error("Could not set '%s'", buf.buf);
+			}
+		}
+	}
+
+	/*
+	 * First remove symrefs, then rename the rest, finally create
+	 * the new symrefs.
+	 */
+	for_each_ref(read_remote_branches, &rename);
+	for (i = 0; i < remote_branches.nr; i++) {
+		struct string_list_item *item = remote_branches.items + i;
+		int flag = 0;
+		unsigned char sha1[20];
+		const char *symref;
+
+		symref = resolve_ref(item->string, sha1, 1, &flag);
+		if (!(flag & REF_ISSYMREF))
+			continue;
+		if (delete_ref(item->string, NULL, REF_NODEREF))
+			die("deleting '%s' failed", item->string);
+	}
+	for (i = 0; i < remote_branches.nr; i++) {
+		struct string_list_item *item = remote_branches.items + i;
+
+		if (item->util)
+			continue;
+		strbuf_reset(&buf);
+		strbuf_addstr(&buf, item->string);
+		strbuf_splice(&buf, strlen("refs/remotes/"), strlen(rename.old),
+				rename.new, strlen(rename.new));
+		strbuf_reset(&buf2);
+		strbuf_addf(&buf2, "remote: renamed %s to %s",
+				item->string, buf.buf);
+		if (rename_ref(item->string, buf.buf, buf2.buf))
+			die("renaming '%s' failed", item->string);
+	}
+	for (i = 0; i < remote_branches.nr; i++) {
+		struct string_list_item *item = remote_branches.items + i;
+
+		if (!item->util)
+			continue;
+		strbuf_reset(&buf);
+		strbuf_addstr(&buf, item->string);
+		strbuf_splice(&buf, strlen("refs/remotes/"), strlen(rename.old),
+				rename.new, strlen(rename.new));
+		strbuf_reset(&buf2);
+		strbuf_addstr(&buf2, item->util);
+		strbuf_splice(&buf2, strlen("refs/remotes/"), strlen(rename.old),
+				rename.new, strlen(rename.new));
+		strbuf_reset(&buf3);
+		strbuf_addf(&buf3, "remote: renamed %s to %s",
+				item->string, buf.buf);
+		if (create_symref(buf.buf, buf2.buf, buf3.buf))
+			die("creating '%s' failed", buf.buf);
+	}
+	return 0;
+}
+
 static int remove_branches(struct string_list *branches)
 {
 	int i, result = 0;
