	return 0;
}

static int push_refs_with_export(struct transport *transport,
		struct ref *remote_refs, int flags)
{
	struct ref *ref;
	struct child_process *helper, exporter;
	struct helper_data *data = transport->data;
	char *export_marks = NULL, *import_marks = NULL;
	struct string_list revlist_args = { NULL, 0, 0 };
	struct strbuf buf = STRBUF_INIT;

	helper = get_helper(transport);

	write_constant(helper->in, "export\n");

	recvline(data, &buf);
	if (debug)
		fprintf(stderr, "Debug: Got export_marks '%s'\n", buf.buf);
	if (buf.len) {
		struct strbuf arg = STRBUF_INIT;
		strbuf_addstr(&arg, "--export-marks=");
		strbuf_addbuf(&arg, &buf);
		export_marks = strbuf_detach(&arg, NULL);
	}

	recvline(data, &buf);
	if (debug)
		fprintf(stderr, "Debug: Got import_marks '%s'\n", buf.buf);
	if (buf.len) {
		struct strbuf arg = STRBUF_INIT;
		strbuf_addstr(&arg, "--import-marks=");
		strbuf_addbuf(&arg, &buf);
		import_marks = strbuf_detach(&arg, NULL);
	}

	strbuf_reset(&buf);

	for (ref = remote_refs; ref; ref = ref->next) {
		char *private;
		unsigned char sha1[20];

		if (!data->refspecs)
			continue;
		private = apply_refspecs(data->refspecs, data->refspec_nr, ref->name);
		if (private && !get_sha1(private, sha1)) {
			strbuf_addf(&buf, "^%s", private);
			string_list_append(strbuf_detach(&buf, NULL), &revlist_args);
		}

		string_list_append(ref->name, &revlist_args);

	}

	if (get_exporter(transport, &exporter,
			 export_marks, import_marks, &revlist_args))
		die("Couldn't run fast-export");

	data->no_disconnect_req = 1;
	finish_command(&exporter);
	disconnect_helper(transport);
	return 0;
}

static int push_refs(struct transport *transport,
		struct ref *remote_refs, int flags)
{
	struct helper_data *data = transport->data;

	if (process_connect(transport, 1)) {
		do_take_over(transport);
		return transport->push_refs(transport, remote_refs, flags);
	}

	if (!remote_refs) {
		fprintf(stderr, "No refs in common and none specified; doing nothing.\n"
			"Perhaps you should specify a branch such as 'master'.\n");
		return 0;
	}

	if (data->push)
		return push_refs_with_push(transport, remote_refs, flags);

	if (data->export)
		return push_refs_with_export(transport, remote_refs, flags);

	return -1;
}


static int has_attribute(const char *attrs, const char *attr) {
	int len;
	if (!attrs)