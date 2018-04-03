 			sanity_check_refcnt(sb);
 	}
 }
+
+static const char *get_next_line(const char *start, const char *end)
+{
+	const char *nl = memchr(start, '\n', end - start);
+	return nl ? nl + 1 : end;
+}
+
+/*
+ * To allow quick access to the contents of nth line in the
+ * final image, prepare an index in the scoreboard.
+ */
+static int prepare_lines(struct blame_scoreboard *sb)
+{
+	const char *buf = sb->final_buf;
+	unsigned long len = sb->final_buf_size;
+	const char *end = buf + len;
+	const char *p;
+	int *lineno;
+	int num = 0;
+
+	for (p = buf; p < end; p = get_next_line(p, end))
+		num++;
+
+	ALLOC_ARRAY(sb->lineno, num + 1);
+	lineno = sb->lineno;
+
+	for (p = buf; p < end; p = get_next_line(p, end))
+		*lineno++ = p - buf;
+
+	*lineno = len;
+
+	sb->num_lines = num;
+	return sb->num_lines;
+}
+
+static struct commit *find_single_final(struct rev_info *revs,
+					const char **name_p)
+{
+	int i;
+	struct commit *found = NULL;
+	const char *name = NULL;
+
+	for (i = 0; i < revs->pending.nr; i++) {
+		struct object *obj = revs->pending.objects[i].item;
+		if (obj->flags & UNINTERESTING)
+			continue;
+		obj = deref_tag(obj, NULL, 0);
+		if (obj->type != OBJ_COMMIT)
+			die("Non commit %s?", revs->pending.objects[i].name);
+		if (found)
+			die("More than one commit to dig from %s and %s?",
+			    revs->pending.objects[i].name, name);
+		found = (struct commit *)obj;
+		name = revs->pending.objects[i].name;
+	}
+	if (name_p)
+		*name_p = name;
+	return found;
+}
+
+static struct commit *dwim_reverse_initial(struct rev_info *revs,
+					   const char **name_p)
+{
+	/*
+	 * DWIM "git blame --reverse ONE -- PATH" as
+	 * "git blame --reverse ONE..HEAD -- PATH" but only do so
+	 * when it makes sense.
+	 */
+	struct object *obj;
+	struct commit *head_commit;
+	unsigned char head_sha1[20];
+
+	if (revs->pending.nr != 1)
+		return NULL;
+
+	/* Is that sole rev a committish? */
+	obj = revs->pending.objects[0].item;
+	obj = deref_tag(obj, NULL, 0);
+	if (obj->type != OBJ_COMMIT)
+		return NULL;
+
+	/* Do we have HEAD? */
+	if (!resolve_ref_unsafe("HEAD", RESOLVE_REF_READING, head_sha1, NULL))
+		return NULL;
+	head_commit = lookup_commit_reference_gently(head_sha1, 1);
+	if (!head_commit)
+		return NULL;
+
+	/* Turn "ONE" into "ONE..HEAD" then */
+	obj->flags |= UNINTERESTING;
+	add_pending_object(revs, &head_commit->object, "HEAD");
+
+	if (name_p)
+		*name_p = revs->pending.objects[0].name;
+	return (struct commit *)obj;
+}
+
+static struct commit *find_single_initial(struct rev_info *revs,
+					  const char **name_p)
+{
+	int i;
+	struct commit *found = NULL;
+	const char *name = NULL;
+
+	/*
+	 * There must be one and only one negative commit, and it must be
+	 * the boundary.
+	 */
+	for (i = 0; i < revs->pending.nr; i++) {
+		struct object *obj = revs->pending.objects[i].item;
+		if (!(obj->flags & UNINTERESTING))
+			continue;
+		obj = deref_tag(obj, NULL, 0);
+		if (obj->type != OBJ_COMMIT)
+			die("Non commit %s?", revs->pending.objects[i].name);
+		if (found)
+			die("More than one commit to dig up from, %s and %s?",
+			    revs->pending.objects[i].name, name);
+		found = (struct commit *) obj;
+		name = revs->pending.objects[i].name;
+	}
+
+	if (!name)
+		found = dwim_reverse_initial(revs, &name);
+	if (!name)
+		die("No commit to dig up from?");
+
+	if (name_p)
+		*name_p = name;
+	return found;
+}
+
+void init_scoreboard(struct blame_scoreboard *sb)
+{
+	memset(sb, 0, sizeof(struct blame_scoreboard));
+	sb->move_score = BLAME_DEFAULT_MOVE_SCORE;
+	sb->copy_score = BLAME_DEFAULT_COPY_SCORE;
+}
+
+void setup_scoreboard(struct blame_scoreboard *sb, const char *path, struct blame_origin **orig)
+{
+	const char *final_commit_name = NULL;
+	struct blame_origin *o;
+	struct commit *final_commit = NULL;
+	enum object_type type;
+
+	if (sb->reverse && sb->contents_from)
+		die(_("--contents and --reverse do not blend well."));
+
+	if (!sb->reverse) {
+		sb->final = find_single_final(sb->revs, &final_commit_name);
+		sb->commits.compare = compare_commits_by_commit_date;
+	} else {
+		sb->final = find_single_initial(sb->revs, &final_commit_name);
+		sb->commits.compare = compare_commits_by_reverse_commit_date;
+	}
+
+	if (sb->final && sb->contents_from)
+		die(_("cannot use --contents with final commit object name"));
+
+	if (sb->reverse && sb->revs->first_parent_only)
+		sb->revs->children.name = NULL;
+
+	if (!sb->final) {
+		/*
+		 * "--not A B -- path" without anything positive;
+		 * do not default to HEAD, but use the working tree
+		 * or "--contents".
+		 */
+		setup_work_tree();
+		sb->final = fake_working_tree_commit(&sb->revs->diffopt,
+						     path, sb->contents_from);
+		add_pending_object(sb->revs, &(sb->final->object), ":");
+	}
+
+	if (sb->reverse && sb->revs->first_parent_only) {
+		final_commit = find_single_final(sb->revs, NULL);
+		if (!final_commit)
+			die(_("--reverse and --first-parent together require specified latest commit"));
+	}
+
+	/*
+	 * If we have bottom, this will mark the ancestors of the
+	 * bottom commits we would reach while traversing as
+	 * uninteresting.
+	 */
+	if (prepare_revision_walk(sb->revs))
+		die(_("revision walk setup failed"));
+
+	if (sb->reverse && sb->revs->first_parent_only) {
+		struct commit *c = final_commit;
+
+		sb->revs->children.name = "children";
+		while (c->parents &&
+		       oidcmp(&c->object.oid, &sb->final->object.oid)) {
+			struct commit_list *l = xcalloc(1, sizeof(*l));
+
+			l->item = c;
+			if (add_decoration(&sb->revs->children,
+					   &c->parents->item->object, l))
+				die("BUG: not unique item in first-parent chain");
+			c = c->parents->item;
+		}
+
+		if (oidcmp(&c->object.oid, &sb->final->object.oid))
+			die(_("--reverse --first-parent together require range along first-parent chain"));
+	}
+
+	if (is_null_oid(&sb->final->object.oid)) {
+		o = sb->final->util;
+		sb->final_buf = xmemdupz(o->file.ptr, o->file.size);
+		sb->final_buf_size = o->file.size;
+	}
+	else {
+		o = get_origin(sb->final, path);
+		if (fill_blob_sha1_and_mode(o))
+			die(_("no such path %s in %s"), path, final_commit_name);
+
+		if (DIFF_OPT_TST(&sb->revs->diffopt, ALLOW_TEXTCONV) &&
+		    textconv_object(path, o->mode, &o->blob_oid, 1, (char **) &sb->final_buf,
+				    &sb->final_buf_size))
+			;
+		else
+			sb->final_buf = read_sha1_file(o->blob_oid.hash, &type,
+						       &sb->final_buf_size);
+
+		if (!sb->final_buf)
+			die(_("cannot read blob %s for path %s"),
+			    oid_to_hex(&o->blob_oid),
+			    path);
+	}
+	sb->num_read_blob++;
+	prepare_lines(sb);
+
+	if (orig)
+		*orig = o;
+}
