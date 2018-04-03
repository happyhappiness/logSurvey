 	return -1;
 }
 
+static int push_refs(struct transport *transport,
+		struct ref *remote_refs, int flags)
+{
+	int force_all = flags & TRANSPORT_PUSH_FORCE;
+	int mirror = flags & TRANSPORT_PUSH_MIRROR;
+	struct helper_data *data = transport->data;
+	struct strbuf buf = STRBUF_INIT;
+	struct child_process *helper;
+	struct ref *ref;
+
+	if (!remote_refs)
+		return 0;
+
+	helper = get_helper(transport);
+	if (!data->push)
+		return 1;
+
+	for (ref = remote_refs; ref; ref = ref->next) {
+		if (ref->peer_ref)
+			hashcpy(ref->new_sha1, ref->peer_ref->new_sha1);
+		else if (!mirror)
+			continue;
+
+		ref->deletion = is_null_sha1(ref->new_sha1);
+		if (!ref->deletion &&
+			!hashcmp(ref->old_sha1, ref->new_sha1)) {
+			ref->status = REF_STATUS_UPTODATE;
+			continue;
+		}
+
+		if (force_all)
+			ref->force = 1;
+
+		strbuf_addstr(&buf, "push ");
+		if (!ref->deletion) {
+			if (ref->force)
+				strbuf_addch(&buf, '+');
+			if (ref->peer_ref)
+				strbuf_addstr(&buf, ref->peer_ref->name);
+			else
+				strbuf_addstr(&buf, sha1_to_hex(ref->new_sha1));
+		}
+		strbuf_addch(&buf, ':');
+		strbuf_addstr(&buf, ref->name);
+		strbuf_addch(&buf, '\n');
+	}
+
+	transport->verbose = flags & TRANSPORT_PUSH_VERBOSE ? 1 : 0;
+	standard_options(transport);
+
+	if (flags & TRANSPORT_PUSH_DRY_RUN) {
+		if (set_helper_option(transport, "dry-run", "true") != 0)
+			die("helper %s does not support dry-run", data->name);
+	}
+
+	strbuf_addch(&buf, '\n');
+	if (write_in_full(helper->in, buf.buf, buf.len) != buf.len)
+		exit(128);
+
+	ref = remote_refs;
+	while (1) {
+		char *refname, *msg;
+		int status;
+
+		strbuf_reset(&buf);
+		if (strbuf_getline(&buf, data->out, '\n') == EOF)
+			exit(128); /* child died, message supplied already */
+		if (!buf.len)
+			break;
+
+		if (!prefixcmp(buf.buf, "ok ")) {
+			status = REF_STATUS_OK;
+			refname = buf.buf + 3;
+		} else if (!prefixcmp(buf.buf, "error ")) {
+			status = REF_STATUS_REMOTE_REJECT;
+			refname = buf.buf + 6;
+		} else
+			die("expected ok/error, helper said '%s'\n", buf.buf);
+
+		msg = strchr(refname, ' ');
+		if (msg) {
+			struct strbuf msg_buf = STRBUF_INIT;
+			const char *end;
+
+			*msg++ = '\0';
+			if (!unquote_c_style(&msg_buf, msg, &end))
+				msg = strbuf_detach(&msg_buf, NULL);
+			else
+				msg = xstrdup(msg);
+			strbuf_release(&msg_buf);
+
+			if (!strcmp(msg, "no match")) {
+				status = REF_STATUS_NONE;
+				free(msg);
+				msg = NULL;
+			}
+			else if (!strcmp(msg, "up to date")) {
+				status = REF_STATUS_UPTODATE;
+				free(msg);
+				msg = NULL;
+			}
+			else if (!strcmp(msg, "non-fast forward")) {
+				status = REF_STATUS_REJECT_NONFASTFORWARD;
+				free(msg);
+				msg = NULL;
+			}
+		}
+
+		if (ref)
+			ref = find_ref_by_name(ref, refname);
+		if (!ref)
+			ref = find_ref_by_name(remote_refs, refname);
+		if (!ref) {
+			warning("helper reported unexpected status of %s", refname);
+			continue;
+		}
+
+		ref->status = status;
+		ref->remote_status = msg;
+	}
+	strbuf_release(&buf);
+	return 0;
+}
+
 static struct ref *get_refs_list(struct transport *transport, int for_push)
 {
 	struct helper_data *data = transport->data;
