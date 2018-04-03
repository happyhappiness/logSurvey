 	const char *path = rr_item->string;
 	const struct rerere_id *id = rr_item->util;
 
-	/* Is there a recorded resolution we could attempt to apply? */
-	if (has_rerere_resolution(id)) {
+	if (!has_rerere_preimage(id)) {
+		/*
+		 * We are the first to encounter this conflict.  Ask
+		 * handle_file() to write the normalized contents to
+		 * the "preimage" file.
+		 */
+		handle_file(path, NULL, rerere_path(id, "preimage"));
+		if (id->collection->status & RR_HAS_POSTIMAGE) {
+			const char *path = rerere_path(id, "postimage");
+			if (unlink(path))
+				die_errno("cannot unlink stray '%s'", path);
+			id->collection->status &= ~RR_HAS_POSTIMAGE;
+		}
+		id->collection->status |= RR_HAS_PREIMAGE;
+		fprintf(stderr, "Recorded preimage for '%s'\n", path);
+		return;
+	} else if (has_rerere_resolution(id)) {
+		/* Is there a recorded resolution we could attempt to apply? */
 		if (merge(id, path))
 			return; /* failed to replay */
 
