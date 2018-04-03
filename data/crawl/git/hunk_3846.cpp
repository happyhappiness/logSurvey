 	return last;
 }
 
-static int write_discovery(int in, int out, void *data)
-{
-	struct discovery *heads = data;
-	int err = 0;
-	if (write_in_full(out, heads->buf, heads->len) != heads->len)
-		err = 1;
-	close(out);
-	return err;
-}
-
 static struct ref *parse_git_refs(struct discovery *heads, int for_push)
 {
 	struct ref *list = NULL;
-	struct async async;
-
-	memset(&async, 0, sizeof(async));
-	async.proc = write_discovery;
-	async.data = heads;
-	async.out = -1;
-
-	if (start_async(&async))
-		die("cannot start thread to parse advertised refs");
-	get_remote_heads(async.out, NULL, 0, &list,
-			for_push ? REF_NORMAL : 0, NULL);
-	close(async.out);
-	if (finish_async(&async))
-		die("ref parsing thread failed");
+	get_remote_heads(-1, heads->buf, heads->len, &list,
+			 for_push ? REF_NORMAL : 0, NULL);
 	return list;
 }
 