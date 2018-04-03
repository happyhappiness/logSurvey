 		error("failed to read object %s at offset %"PRIuMAX" from %s",
 		      sha1_to_hex(sha1), (uintmax_t)e.offset, e.p->pack_name);
 		mark_bad_packed_object(e.p, sha1);
-		data = read_sha1_file(sha1, type, size);
+		data = read_object(sha1, type, size);
 	}
 	return data;
 }
