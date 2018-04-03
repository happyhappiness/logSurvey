 		struct transport *transport;
 		const struct ref *ref;
 		struct strbuf buf;
-		int i, got_states;
+		int i;
 
 		states.remote = remote_get(*argv);
 		if (!states.remote)
 			return error("No such remote: %s", *argv);
-		transport = transport_get(NULL, states.remote->url_nr > 0 ?
-			states.remote->url[0] : NULL);
-		ref = transport_get_remote_refs(transport);
-		transport_disconnect(transport);
 
 		read_branches();
-		got_states = get_ref_states(ref, &states);
-		if (got_states)
-			result = error("Error getting local info for '%s'",
-					states.remote->name);
+
+		if (!no_query) {
+			transport = transport_get(NULL,
+				states.remote->url_nr > 0 ?
+				states.remote->url[0] : NULL);
+			ref = transport_get_remote_refs(transport);
+			transport_disconnect(transport);
+
+			get_ref_states(ref, &states);
+		}
 
 		if (prune) {
 			for (i = 0; i < states.stale.nr; i++) {
