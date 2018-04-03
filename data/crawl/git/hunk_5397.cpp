 
 	/* if not appending, truncate FETCH_HEAD */
 	if (!append && !dry_run) {
-		char *filename = git_path("FETCH_HEAD");
-		FILE *fp = fopen(filename, "w");
-		if (!fp)
-			return error("cannot open %s: %s\n", filename, strerror(errno));
-		fclose(fp);
+		int errcode = truncate_fetch_head();
+		if (errcode)
+			return errcode;
 	}
 
 	ref_map = get_ref_map(transport, refs, ref_count, tags, &autotags);
