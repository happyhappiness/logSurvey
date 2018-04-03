 	return 1;
 }
 
-static struct ref *local_refs, **local_tail;
 static struct ref *remote_refs, **remote_tail;
 
-static int one_local_ref(const char *refname, const unsigned char *sha1, int flag, void *cb_data)
-{
-	struct ref *ref;
-	int len = strlen(refname) + 1;
-	ref = xcalloc(1, sizeof(*ref) + len);
-	hashcpy(ref->new_sha1, sha1);
-	memcpy(ref->name, refname, len);
-	*local_tail = ref;
-	local_tail = &ref->next;
-	return 0;
-}
-
 static void one_remote_ref(char *refname)
 {
 	struct ref *ref;
 	struct object *obj;
 
 	ref = alloc_ref(refname);
 
-	if (http_fetch_ref(remote->url, ref) != 0) {
+	if (http_fetch_ref(repo->url, ref) != 0) {
 		fprintf(stderr,
 			"Unable to fetch ref %s from %s\n",
-			refname, remote->url);
+			refname, repo->url);
 		free(ref);
 		return;
 	}
