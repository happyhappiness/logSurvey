 	int i, errs;
 	struct remote *remote = remote_get(repo);
 
-	if (!remote)
-		die("bad repository '%s'", repo);
+	if (!remote) {
+		if (repo)
+			die("bad repository '%s'", repo);
+		die("No destination configured to push to.");
+	}
 
 	if (remote->mirror)
 		flags |= (TRANSPORT_PUSH_MIRROR|TRANSPORT_PUSH_FORCE);
