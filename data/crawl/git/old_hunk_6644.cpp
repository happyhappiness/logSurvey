		 * This is costly but should happen only in the presence
		 * of a corrupted pack, and is better than failing outright.
		 */
		struct revindex_entry *revidx = find_pack_revindex(p, base_offset);
		const unsigned char *base_sha1 =
					nth_packed_object_sha1(p, revidx->nr);
		error("failed to read delta base object %s"
		      " at offset %"PRIuMAX" from %s",
		      sha1_to_hex(base_sha1), (uintmax_t)base_offset,