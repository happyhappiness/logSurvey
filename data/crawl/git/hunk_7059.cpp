 	off_t base_offset;
 
 	base_offset = get_delta_base(p, w_curs, &curpos, *type, obj_offset);
+	if (!base_offset) {
+		error("failed to validate delta base reference "
+		      "at offset %"PRIuMAX" from %s",
+		      (uintmax_t)curpos, p->pack_name);
+		return NULL;
+	}
 	base = cache_or_unpack_entry(p, base_offset, &base_size, type, 0);
-	if (!base)
-		die("failed to read delta base object"
-		    " at %"PRIuMAX" from %s",
-		    (uintmax_t)base_offset, p->pack_name);
+	if (!base) {
+		/*
+		 * We're probably in deep shit, but let's try to fetch
+		 * the required base anyway from another pack or loose.
+		 * This is costly but should happen only in the presence
+		 * of a corrupted pack, and is better than failing outright.
+		 */
+		struct revindex_entry *revidx = find_pack_revindex(p, base_offset);
+		const unsigned char *base_sha1 =
+					nth_packed_object_sha1(p, revidx->nr);
+		error("failed to read delta base object %s"
+		      " at offset %"PRIuMAX" from %s",
+		      sha1_to_hex(base_sha1), (uintmax_t)base_offset,
+		      p->pack_name);
+		mark_bad_packed_object(p, base_sha1);
+		base = read_sha1_file(base_sha1, type, &base_size);
+		if (!base)
+			return NULL;
+	}
 
 	delta_data = unpack_compressed_entry(p, w_curs, curpos, delta_size);
-	if (!delta_data)
-		die("failed to unpack compressed delta"
-		    " at %"PRIuMAX" from %s",
-		    (uintmax_t)curpos, p->pack_name);
+	if (!delta_data) {
+		error("failed to unpack compressed delta "
+		      "at offset %"PRIuMAX" from %s",
+		      (uintmax_t)curpos, p->pack_name);
+		free(base);
+		return NULL;
+	}
 	result = patch_delta(base, base_size,
 			     delta_data, delta_size,
 			     sizep);
