 	revs->limited = 1;
 }
 
+static int dotdot_missing(const char *arg, char *dotdot,
+			  struct rev_info *revs, int symmetric)
+{
+	if (revs->ignore_missing)
+		return 0;
+	/* de-munge so we report the full argument */
+	*dotdot = '.';
+	die(symmetric
+	    ? "Invalid symmetric difference expression %s"
+	    : "Invalid revision range %s", arg);
+}
+
+static int handle_dotdot_1(const char *arg, char *dotdot,
+			   struct rev_info *revs, int flags,
+			   int cant_be_filename)
+{
+	const char *a_name, *b_name;
+	struct object_id a_oid, b_oid;
+	struct object *a_obj, *b_obj;
+	unsigned int a_flags, b_flags;
+	int symmetric = 0;
+	unsigned int flags_exclude = flags ^ (UNINTERESTING | BOTTOM);
+
+	a_name = arg;
+	if (!*a_name)
+		a_name = "HEAD";
+
+	b_name = dotdot + 2;
+	if (*b_name == '.') {
+		symmetric = 1;
+		b_name++;
+	}
+	if (!*b_name)
+		b_name = "HEAD";
+
+	if (get_sha1_committish(a_name, a_oid.hash) ||
+	    get_sha1_committish(b_name, b_oid.hash))
+		return -1;
+
+	if (!cant_be_filename) {
+		*dotdot = '.';
+		verify_non_filename(revs->prefix, arg);
+		*dotdot = '\0';
+	}
+
+	a_obj = parse_object(a_oid.hash);
+	b_obj = parse_object(b_oid.hash);
+	if (!a_obj || !b_obj)
+		return dotdot_missing(arg, dotdot, revs, symmetric);
+
+	if (!symmetric) {
+		/* just A..B */
+		b_flags = flags;
+		a_flags = flags_exclude;
+	} else {
+		/* A...B -- find merge bases between the two */
+		struct commit *a, *b;
+		struct commit_list *exclude;
+
+		a = lookup_commit_reference(a_obj->oid.hash);
+		b = lookup_commit_reference(b_obj->oid.hash);
+		if (!a || !b)
+			return dotdot_missing(arg, dotdot, revs, symmetric);
+
+		exclude = get_merge_bases(a, b);
+		add_rev_cmdline_list(revs, exclude, REV_CMD_MERGE_BASE,
+				     flags_exclude);
+		add_pending_commit_list(revs, exclude, flags_exclude);
+		free_commit_list(exclude);
+
+		b_flags = flags;
+		a_flags = flags | SYMMETRIC_LEFT;
+	}
+
+	a_obj->flags |= a_flags;
+	b_obj->flags |= b_flags;
+	add_rev_cmdline(revs, a_obj, a_name, REV_CMD_LEFT, a_flags);
+	add_rev_cmdline(revs, b_obj, b_name, REV_CMD_RIGHT, b_flags);
+	add_pending_object(revs, a_obj, a_name);
+	add_pending_object(revs, b_obj, b_name);
+	return 0;
+}
+
+static int handle_dotdot(const char *arg,
+			 struct rev_info *revs, int flags,
+			 int cant_be_filename)
+{
+	char *dotdot = strstr(arg, "..");
+	int ret;
+
+	if (!dotdot)
+		return -1;
+
+	*dotdot = '\0';
+	ret = handle_dotdot_1(arg, dotdot, revs, flags, cant_be_filename);
+	*dotdot = '.';
+
+	return ret;
+}
+
 int handle_revision_arg(const char *arg_, struct rev_info *revs, int flags, unsigned revarg_opt)
 {
 	struct object_context oc;
-	char *dotdot;
 	char *mark;
 	struct object *object;
 	unsigned char sha1[20];
