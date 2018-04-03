 	if (finish_connect(conn))
 		return 1;
 
-	ret = !ref || sought.nr;
+	ret = !ref;
 
 	/*
 	 * If the heads to pull were given, we should have consumed
 	 * all of them by matching the remote.  Otherwise, 'git fetch
 	 * remote no-such-ref' would silently succeed without issuing
 	 * an error.
 	 */
-	for (i = 0; i < sought.nr; i++)
-		error("no such remote ref %s", sought.items[i].string);
+	for (i = 0; i < nr_sought; i++) {
+		if (!sought[i] || sought[i]->matched)
+			continue;
+		error("no such remote ref %s", sought[i]->name);
+		ret = 1;
+	}
+
 	while (ref) {
 		printf("%s %s\n",
 		       sha1_to_hex(ref->old_sha1), ref->name);
