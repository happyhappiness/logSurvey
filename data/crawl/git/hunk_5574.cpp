 {
 	struct transport *ret = xcalloc(1, sizeof(*ret));
 
+	if (!remote)
+		die("No remote provided to transport_get()");
+
 	ret->remote = remote;
 	ret->url = url;
 
