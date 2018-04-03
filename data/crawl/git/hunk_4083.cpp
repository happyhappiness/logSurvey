 	if (finish_connect(conn))
 		return 1;
 
-	ret = !ref;
-	if (sought.nr) {
-		/* If the heads to pull were given, we should have
-		 * consumed all of them by matching the remote.
-		 * Otherwise, 'git fetch remote no-such-ref' would
-		 * silently succeed without issuing an error.
-		 */
-		for (i = 0; i < sought.nr; i++)
-			error("no such remote ref %s", sought.items[i].string);
-		ret = 1;
-	}
+	ret = !ref || sought.nr;
+
+	/*
+	 * If the heads to pull were given, we should have consumed
+	 * all of them by matching the remote.  Otherwise, 'git fetch
+	 * remote no-such-ref' would silently succeed without issuing
+	 * an error.
+	 */
+	for (i = 0; i < sought.nr; i++)
+		error("no such remote ref %s", sought.items[i].string);
 	while (ref) {
 		printf("%s %s\n",
 		       sha1_to_hex(ref->old_sha1), ref->name);