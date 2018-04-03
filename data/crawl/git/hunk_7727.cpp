 		die("Don't know how to fetch from %s", transport->url);
 
 	/* if not appending, truncate FETCH_HEAD */
-	if (!append)
-		fclose(fopen(git_path("FETCH_HEAD"), "w"));
+	if (!append) {
+		char *filename = git_path("FETCH_HEAD");
+		FILE *fp = fopen(filename, "w");
+		if (!fp)
+			return error("cannot open %s: %s\n", filename, strerror(errno));
+		fclose(fp);
+	}
 
 	ref_map = get_ref_map(transport, refs, ref_count, tags, &autotags);
 