 		struct revindex_entry *revidx;
 		off_t offset;
 
-		if (entry->delta) {
+		if (entry->delta)
 			type = (allow_ofs_delta && entry->delta->idx.offset) ?
 				OBJ_OFS_DELTA : OBJ_REF_DELTA;
-			reused_delta++;
-		}
 		hdrlen = encode_header(type, entry->size, header);
+
 		offset = entry->in_pack_offset;
 		revidx = find_pack_revindex(p, offset);
 		datalen = revidx[1].offset - offset;
 		if (!pack_to_stdout && p->index_version > 1 &&
-		    check_pack_crc(p, &w_curs, offset, datalen, revidx->nr))
-			die("bad packed object CRC for %s", sha1_to_hex(entry->idx.sha1));
+		    check_pack_crc(p, &w_curs, offset, datalen, revidx->nr)) {
+			error("bad packed object CRC for %s", sha1_to_hex(entry->idx.sha1));
+			unuse_pack(&w_curs);
+			goto no_reuse;
+		}
+
 		offset += entry->in_pack_header_size;
 		datalen -= entry->in_pack_header_size;
+		if (!pack_to_stdout && p->index_version == 1 &&
+		    check_pack_inflate(p, &w_curs, offset, datalen, entry->size)) {
+			error("corrupt packed object for %s", sha1_to_hex(entry->idx.sha1));
+			unuse_pack(&w_curs);
+			goto no_reuse;
+		}
+
 		if (type == OBJ_OFS_DELTA) {
 			off_t ofs = entry->idx.offset - entry->delta->idx.offset;
 			unsigned pos = sizeof(dheader) - 1;
