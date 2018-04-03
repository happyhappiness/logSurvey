 
 	ref = alloc_ref(ls->dentry_name);
 
-	if (http_fetch_ref(remote->url, ref) != 0) {
+	if (http_fetch_ref(repo->url, ref) != 0) {
 		fprintf(stderr,
 			"Unable to fetch ref %s from %s\n",
-			ls->dentry_name, remote->url);
+			ls->dentry_name, repo->url);
 		aborted = 1;
 		free(ref);
 		return;
