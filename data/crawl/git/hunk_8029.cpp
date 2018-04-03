 	/* disconnect */	disconnect_walker
 };
 
+struct bundle_transport_data {
+	int fd;
+	struct bundle_header header;
+};
+
+static struct ref *get_refs_from_bundle(const struct transport *transport)
+{
+	struct bundle_transport_data *data = transport->data;
+	struct ref *result = NULL;
+	int i;
+
+	if (data->fd > 0)
+		close(data->fd);
+	data->fd = read_bundle_header(transport->url, &data->header);
+	if (data->fd < 0)
+		die ("Could not read bundle '%s'.", transport->url);
+	for (i = 0; i < data->header.references.nr; i++) {
+		struct ref_list_entry *e = data->header.references.list + i;
+		struct ref *ref = alloc_ref(strlen(e->name));
+		hashcpy(ref->old_sha1, e->sha1);
+		strcpy(ref->name, e->name);
+		ref->next = result;
+		result = ref;
+	}
+	return result;
+}
+
+static int fetch_refs_from_bundle(const struct transport *transport,
+			       int nr_heads, char **heads)
+{
+	struct bundle_transport_data *data = transport->data;
+	return unbundle(&data->header, data->fd);
+}
+
+static int close_bundle(struct transport *transport)
+{
+	struct bundle_transport_data *data = transport->data;
+	if (data->fd > 0)
+		close(data->fd);
+	return 0;
+}
+
 static const struct transport_ops bundle_transport = {
+	/* set_option */	NULL,
+	/* get_refs_list */	get_refs_from_bundle,
+	/* fetch_refs */	fetch_refs_from_bundle,
+	/* fetch_objs */	NULL,
+	/* push */		NULL,
+	/* disconnect */	close_bundle
 };
 
 struct git_transport_data {
