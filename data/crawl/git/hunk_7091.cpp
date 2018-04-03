 	printf("\n");
 }
 
-static int show_or_prune(int argc, const char **argv, int prune)
+static int get_remote_ref_states(const char *name,
+				 struct ref_states *states,
+				 int query)
+{
+	struct transport *transport;
+	const struct ref *ref;
+
+	states->remote = remote_get(name);
+	if (!states->remote)
+		return error("No such remote: %s", name);
+
+	read_branches();
+
+	if (query) {
+		transport = transport_get(NULL, states->remote->url_nr > 0 ?
+			states->remote->url[0] : NULL);
+		ref = transport_get_remote_refs(transport);
+		transport_disconnect(transport);
+
+		get_ref_states(ref, states);
+	}
+
+	return 0;
+}
+
+static int show(int argc, const char **argv)
 {
 	int no_query = 0, result = 0;
 	struct option options[] = {
