 	return !!err;
 }
 
+#ifndef NO_CURL
+static int missing__target(int code, int result)
+{
+	return	/* file:// URL -- do we ever use one??? */
+		(result == CURLE_FILE_COULDNT_READ_FILE) ||
+		/* http:// and https:// URL */
+		(code == 404 && result == CURLE_HTTP_RETURNED_ERROR) ||
+		/* ftp:// URL */
+		(code == 550 && result == CURLE_FTP_COULDNT_RETR_FILE)
+		;
+}
+
+#define missing_target(a) missing__target((a)->http_code, (a)->curl_result)
+
+static struct ref *get_refs_via_curl(const struct transport *transport)
+{
+	struct buffer buffer;
+	char *data, *start, *mid;
+	char *ref_name;
+	char *refs_url;
+	int i = 0;
+
+	struct active_request_slot *slot;
+	struct slot_results results;
+
+	struct ref *refs = NULL;
+	struct ref *ref = NULL;
+	struct ref *last_ref = NULL;
+
+	data = xmalloc(4096);
+	buffer.size = 4096;
+	buffer.posn = 0;
+	buffer.buffer = data;
+
+	refs_url = xmalloc(strlen(transport->url) + 11);
+	sprintf(refs_url, "%s/info/refs", transport->url);
+
+	http_init();
+
+	slot = get_active_slot();
+	slot->results = &results;
+	curl_easy_setopt(slot->curl, CURLOPT_FILE, &buffer);
+	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_buffer);
+	curl_easy_setopt(slot->curl, CURLOPT_URL, refs_url);
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, NULL);
+	if (start_active_slot(slot)) {
+		run_active_slot(slot);
+		if (results.curl_result != CURLE_OK) {
+			if (missing_target(&results)) {
+				free(buffer.buffer);
+				return NULL;
+			} else {
+				free(buffer.buffer);
+				error("%s", curl_errorstr);
+				return NULL;
+			}
+		}
+	} else {
+		free(buffer.buffer);
+		error("Unable to start request");
+		return NULL;
+	}
+
+	http_cleanup();
+
+	data = buffer.buffer;
+	start = NULL;
+	mid = data;
+	while (i < buffer.posn) {
+		if (!start)
+			start = &data[i];
+		if (data[i] == '\t')
+			mid = &data[i];
+		if (data[i] == '\n') {
+			data[i] = 0;
+			ref_name = mid + 1;
+			ref = xmalloc(sizeof(struct ref) +
+				      strlen(ref_name) + 1);
+			memset(ref, 0, sizeof(struct ref));
+			strcpy(ref->name, ref_name);
+			get_sha1_hex(start, ref->old_sha1);
+			if (!refs)
+				refs = ref;
+			if (last_ref)
+				last_ref->next = ref;
+			last_ref = ref;
+			start = NULL;
+		}
+		i++;
+	}
+
+	free(buffer.buffer);
+
+	return refs;
+}
+
+#else
+
+static struct ref *get_refs_via_curl(const struct transport *transport)
+{
+	die("Cannot fetch from '%s' without curl ...", transport->url);
+	return NULL;
+}
+
+#endif
+
 static const struct transport_ops curl_transport = {
 	/* set_option */	NULL,
-	/* push */		curl_transport_push
+	/* get_refs_list */	get_refs_via_curl,
+	/* fetch_refs */	NULL,
+	/* fetch_objs */	fetch_objs_via_walker,
+	/* push */		curl_transport_push,
+	/* disconnect */	disconnect_walker
 };
 
 static const struct transport_ops bundle_transport = {
 };
 
 struct git_transport_data {
 	unsigned thin : 1;
+	unsigned keep : 1;
+
+	int unpacklimit;
 
+	int depth;
+
+	const char *uploadpack;
 	const char *receivepack;
 };
 
 static int set_git_option(struct transport *connection,
 			  const char *name, const char *value)
 {
 	struct git_transport_data *data = connection->data;
-	if (!strcmp(name, TRANS_OPT_RECEIVEPACK)) {
+	if (!strcmp(name, TRANS_OPT_UPLOADPACK)) {
+		data->uploadpack = value;
+		return 0;
+	} else if (!strcmp(name, TRANS_OPT_RECEIVEPACK)) {
 		data->receivepack = value;
 		return 0;
 	} else if (!strcmp(name, TRANS_OPT_THIN)) {
 		data->thin = !!value;
 		return 0;
+	} else if (!strcmp(name, TRANS_OPT_KEEP)) {
+		data->keep = !!value;
+		return 0;
+	} else if (!strcmp(name, TRANS_OPT_UNPACKLIMIT)) {
+		data->unpacklimit = atoi(value);
+		return 0;
+	} else if (!strcmp(name, TRANS_OPT_DEPTH)) {
+		if (!value)
+			data->depth = 0;
+		else
+			data->depth = atoi(value);
+		return 0;
 	}
 	return 1;
 }
 
+static struct ref *get_refs_via_connect(const struct transport *transport)
+{
+	struct git_transport_data *data = transport->data;
+	struct ref *refs;
+	int fd[2];
+	pid_t pid;
+	char *dest = xstrdup(transport->url);
+
+	pid = git_connect(fd, dest, data->uploadpack, 0);
+
+	if (pid < 0)
+		die("Failed to connect to \"%s\"", transport->url);
+
+	get_remote_heads(fd[0], &refs, 0, NULL, 0);
+	packet_flush(fd[1]);
+
+	finish_connect(pid);
+
+	free(dest);
+
+	return refs;
+}
+
+static int fetch_refs_via_pack(const struct transport *transport,
+			       int nr_heads, char **heads)
+{
+	struct git_transport_data *data = transport->data;
+	struct ref *refs;
+	char *dest = xstrdup(transport->url);
+	struct fetch_pack_args args;
+
+	args.uploadpack = data->uploadpack;
+	args.quiet = 0;
+	args.keep_pack = data->keep;
+	args.unpacklimit = data->unpacklimit;
+	args.use_thin_pack = data->thin;
+	args.fetch_all = 0;
+	args.verbose = transport->verbose;
+	args.depth = data->depth;
+	args.no_progress = 0;
+
+	setup_fetch_pack(&args);
+
+	refs = fetch_pack(dest, nr_heads, heads);
+
+	// ???? check that refs got everything?
+
+	/* free the memory used for the refs list ... */
+
+	free_refs(refs);
+
+	free(dest);
+	return 0;
+}
+
 static int git_transport_push(struct transport *transport, int refspec_nr, const char **refspec, int flags) {
 	struct git_transport_data *data = transport->data;
 	const char **argv;
