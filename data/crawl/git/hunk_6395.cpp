 	return (refs ? 0 : -1);
 }
 
-static int git_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags)
+static int refs_pushed(struct ref *ref)
+{
+	for (; ref; ref = ref->next) {
+		switch(ref->status) {
+		case REF_STATUS_NONE:
+		case REF_STATUS_UPTODATE:
+			break;
+		default:
+			return 1;
+		}
+	}
+	return 0;
+}
+
+static void update_tracking_ref(struct remote *remote, struct ref *ref, int verbose)
+{
+	struct refspec rs;
+
+	if (ref->status != REF_STATUS_OK && ref->status != REF_STATUS_UPTODATE)
+		return;
+
+	rs.src = ref->name;
+	rs.dst = NULL;
+
+	if (!remote_find_tracking(remote, &rs)) {
+		if (verbose)
+			fprintf(stderr, "updating local tracking ref '%s'\n", rs.dst);
+		if (ref->deletion) {
+			delete_ref(rs.dst, NULL, 0);
+		} else
+			update_ref("update by push", rs.dst,
+					ref->new_sha1, NULL, 0, 0);
+		free(rs.dst);
+	}
+}
+
+#define SUMMARY_WIDTH (2 * DEFAULT_ABBREV + 3)
+
+static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg)
+{
+	fprintf(stderr, " %c %-*s ", flag, SUMMARY_WIDTH, summary);
+	if (from)
+		fprintf(stderr, "%s -> %s", prettify_ref(from), prettify_ref(to));
+	else
+		fputs(prettify_ref(to), stderr);
+	if (msg) {
+		fputs(" (", stderr);
+		fputs(msg, stderr);
+		fputc(')', stderr);
+	}
+	fputc('\n', stderr);
+}
+
+static const char *status_abbrev(unsigned char sha1[20])
+{
+	return find_unique_abbrev(sha1, DEFAULT_ABBREV);
+}
+
+static void print_ok_ref_status(struct ref *ref)
+{
+	if (ref->deletion)
+		print_ref_status('-', "[deleted]", ref, NULL, NULL);
+	else if (is_null_sha1(ref->old_sha1))
+		print_ref_status('*',
+			(!prefixcmp(ref->name, "refs/tags/") ? "[new tag]" :
+			  "[new branch]"),
+			ref, ref->peer_ref, NULL);
+	else {
+		char quickref[84];
+		char type;
+		const char *msg;
+
+		strcpy(quickref, status_abbrev(ref->old_sha1));
+		if (ref->nonfastforward) {
+			strcat(quickref, "...");
+			type = '+';
+			msg = "forced update";
+		} else {
+			strcat(quickref, "..");
+			type = ' ';
+			msg = NULL;
+		}
+		strcat(quickref, status_abbrev(ref->new_sha1));
+
+		print_ref_status(type, quickref, ref, ref->peer_ref, msg);
+	}
+}
+
+static int print_one_push_status(struct ref *ref, const char *dest, int count)
+{
+	if (!count)
+		fprintf(stderr, "To %s\n", dest);
+
+	switch(ref->status) {
+	case REF_STATUS_NONE:
+		print_ref_status('X', "[no match]", ref, NULL, NULL);
+		break;
+	case REF_STATUS_REJECT_NODELETE:
+		print_ref_status('!', "[rejected]", ref, NULL,
+				"remote does not support deleting refs");
+		break;
+	case REF_STATUS_UPTODATE:
+		print_ref_status('=', "[up to date]", ref,
+				ref->peer_ref, NULL);
+		break;
+	case REF_STATUS_REJECT_NONFASTFORWARD:
+		print_ref_status('!', "[rejected]", ref, ref->peer_ref,
+				"non-fast forward");
+		break;
+	case REF_STATUS_REMOTE_REJECT:
+		print_ref_status('!', "[remote rejected]", ref,
+				ref->deletion ? NULL : ref->peer_ref,
+				ref->remote_status);
+		break;
+	case REF_STATUS_EXPECTING_REPORT:
+		print_ref_status('!', "[remote failure]", ref,
+				ref->deletion ? NULL : ref->peer_ref,
+				"remote failed to report status");
+		break;
+	case REF_STATUS_OK:
+		print_ok_ref_status(ref);
+		break;
+	}
+
+	return 1;
+}
+
+static void print_push_status(const char *dest, struct ref *refs, int verbose)
+{
+	struct ref *ref;
+	int n = 0;
+
+	if (verbose) {
+		for (ref = refs; ref; ref = ref->next)
+			if (ref->status == REF_STATUS_UPTODATE)
+				n += print_one_push_status(ref, dest, n);
+	}
+
+	for (ref = refs; ref; ref = ref->next)
+		if (ref->status == REF_STATUS_OK)
+			n += print_one_push_status(ref, dest, n);
+
+	for (ref = refs; ref; ref = ref->next) {
+		if (ref->status != REF_STATUS_NONE &&
+		    ref->status != REF_STATUS_UPTODATE &&
+		    ref->status != REF_STATUS_OK)
+			n += print_one_push_status(ref, dest, n);
+	}
+}
+
+static void verify_remote_names(int nr_heads, const char **heads)
+{
+	int i;
+
+	for (i = 0; i < nr_heads; i++) {
+		const char *local = heads[i];
+		const char *remote = strrchr(heads[i], ':');
+
+		if (*local == '+')
+			local++;
+
+		/* A matching refspec is okay.  */
+		if (remote == local && remote[1] == '\0')
+			continue;
+
+		remote = remote ? (remote + 1) : local;
+		switch (check_ref_format(remote)) {
+		case 0: /* ok */
+		case CHECK_REF_FORMAT_ONELEVEL:
+			/* ok but a single level -- that is fine for
+			 * a match pattern.
+			 */
+		case CHECK_REF_FORMAT_WILDCARD:
+			/* ok but ends with a pattern-match character */
+			continue;
+		}
+		die("remote part of refspec is not a valid name in %s",
+		    heads[i]);
+	}
+}
+
+static int git_transport_push(struct transport *transport, struct ref *remote_refs, int flags)
 {
 	struct git_transport_data *data = transport->data;
 	struct send_pack_args args;
+	int ret;
+
+	if (!data->conn) {
+		struct ref *tmp_refs;
+		connect_setup(transport, 1, 0);
+
+		get_remote_heads(data->fd[0], &tmp_refs, 0, NULL, REF_NORMAL,
+				 NULL);
+	}
 
-	args.receivepack = data->receivepack;
-	args.send_all = !!(flags & TRANSPORT_PUSH_ALL);
 	args.send_mirror = !!(flags & TRANSPORT_PUSH_MIRROR);
 	args.force_update = !!(flags & TRANSPORT_PUSH_FORCE);
 	args.use_thin_pack = data->thin;
 	args.verbose = !!(flags & TRANSPORT_PUSH_VERBOSE);
 	args.dry_run = !!(flags & TRANSPORT_PUSH_DRY_RUN);
 
-	return send_pack(&args, transport->url, transport->remote, refspec_nr, refspec);
+	ret = send_pack(&args, data->fd, data->conn, remote_refs,
+			&data->extra_have);
+
+	close(data->fd[1]);
+	close(data->fd[0]);
+	ret |= finish_connect(data->conn);
+	data->conn = NULL;
+
+	return ret;
 }
 
 static int disconnect_git(struct transport *transport)
