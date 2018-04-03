 				return 0;
 			}
 			die("object %s cannot be read",
-			    sha1_to_hex(src_entry->idx.sha1));
+			    oid_to_hex(&src_entry->idx.oid));
 		}
 		if (sz != src_size)
 			die("object %s inconsistent object length (%lu vs %lu)",
-			    sha1_to_hex(src_entry->idx.sha1), sz, src_size);
+			    oid_to_hex(&src_entry->idx.oid), sz,
+			    src_size);
 		*mem_usage += sz;
 	}
 	if (!src->index) {
