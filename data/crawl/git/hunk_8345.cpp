 
 	/* Load data if not already done */
 	if (!trg->data) {
-		trg->data = read_sha1_file(trg_entry->sha1, &type, &sz);
+		trg->data = read_sha1_file(trg_entry->idx.sha1, &type, &sz);
 		if (sz != trg_size)
 			die("object %s inconsistent object length (%lu vs %lu)",
-			    sha1_to_hex(trg_entry->sha1), sz, trg_size);
+			    sha1_to_hex(trg_entry->idx.sha1), sz, trg_size);
 	}
 	if (!src->data) {
-		src->data = read_sha1_file(src_entry->sha1, &type, &sz);
+		src->data = read_sha1_file(src_entry->idx.sha1, &type, &sz);
 		if (sz != src_size)
 			die("object %s inconsistent object length (%lu vs %lu)",
-			    sha1_to_hex(src_entry->sha1), sz, src_size);
+			    sha1_to_hex(src_entry->idx.sha1), sz, src_size);
 	}
 	if (!src->index) {
 		src->index = create_delta_index(src->data, src_size);
