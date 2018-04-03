 {
 	const char *path = rr_item->string;
 	struct rerere_id *id = rr_item->util;
+	struct rerere_dir *rr_dir = id->collection;
 	int variant;
 
-	if (id->variant < 0)
-		assign_variant(id);
 	variant = id->variant;
 
-	if (!has_rerere_preimage(id)) {
+	/* Has the user resolved it already? */
+	if (variant >= 0) {
+		if (!handle_file(path, NULL, NULL)) {
+			copy_file(rerere_path(id, "postimage"), path, 0666);
+			id->collection->status[variant] |= RR_HAS_POSTIMAGE;
+			fprintf(stderr, "Recorded resolution for '%s'.\n", path);
+			free_rerere_id(rr_item);
+			rr_item->util = NULL;
+			return;
+		}
 		/*
-		 * We are the first to encounter this conflict.  Ask
-		 * handle_file() to write the normalized contents to
-		 * the "preimage" file.
+		 * There may be other variants that can cleanly
+		 * replay.  Try them and update the variant number for
+		 * this one.
 		 */
-		handle_file(path, NULL, rerere_path(id, "preimage"));
-		if (id->collection->status[variant] & RR_HAS_POSTIMAGE) {
-			const char *path = rerere_path(id, "postimage");
-			if (unlink(path))
-				die_errno("cannot unlink stray '%s'", path);
-			id->collection->status[variant] &= ~RR_HAS_POSTIMAGE;
-		}
-		id->collection->status[variant] |= RR_HAS_PREIMAGE;
-		fprintf(stderr, "Recorded preimage for '%s'\n", path);
-		return;
-	} else if (has_rerere_resolution(id)) {
-		/* Is there a recorded resolution we could attempt to apply? */
-		if (merge(id, path))
-			return; /* failed to replay */
+	}
+
+	/* Does any existing resolution apply cleanly? */
+	for (variant = 0; variant < rr_dir->status_nr; variant++) {
+		const int both = RR_HAS_PREIMAGE | RR_HAS_POSTIMAGE;
+		struct rerere_id vid = *id;
+
+		if ((rr_dir->status[variant] & both) != both)
+			continue;
+
+		vid.variant = variant;
+		if (merge(&vid, path))
+			continue; /* failed to replay */
+
+		/*
+		 * If there already is a different variant that applies
+		 * cleanly, there is no point maintaining our own variant.
+		 */
+		if (0 <= id->variant && id->variant != variant)
+			remove_variant(id);
 
 		if (rerere_autoupdate)
 			string_list_insert(update, path);
 		else
 			fprintf(stderr,
 				"Resolved '%s' using previous resolution.\n",
 				path);
-	} else if (!handle_file(path, NULL, NULL)) {
-		/* The user has resolved it. */
-		copy_file(rerere_path(id, "postimage"), path, 0666);
-		id->collection->status[variant] |= RR_HAS_POSTIMAGE;
-		fprintf(stderr, "Recorded resolution for '%s'.\n", path);
-	} else {
+		free_rerere_id(rr_item);
+		rr_item->util = NULL;
 		return;
 	}
-	free_rerere_id(rr_item);
-	rr_item->util = NULL;
+
+	/* None of the existing one applies; we need a new variant */
+	assign_variant(id);
+
+	variant = id->variant;
+	handle_file(path, NULL, rerere_path(id, "preimage"));
+	if (id->collection->status[variant] & RR_HAS_POSTIMAGE) {
+		const char *path = rerere_path(id, "postimage");
+		if (unlink(path))
+			die_errno("cannot unlink stray '%s'", path);
+		id->collection->status[variant] &= ~RR_HAS_POSTIMAGE;
+	}
+	id->collection->status[variant] |= RR_HAS_PREIMAGE;
+	fprintf(stderr, "Recorded preimage for '%s'\n", path);
 }
 
 static int do_plain_rerere(struct string_list *rr, int fd)
