 		datalen = revidx[1].offset - offset;
 		if (!pack_to_stdout && p->index_version > 1 &&
 		    check_pack_crc(p, &w_curs, offset, datalen, revidx->nr))
-			die("bad packed object CRC for %s", sha1_to_hex(entry->sha1));
+			die("bad packed object CRC for %s", sha1_to_hex(entry->idx.sha1));
 		offset += entry->in_pack_header_size;
 		datalen -= entry->in_pack_header_size;
 		if (obj_type == OBJ_OFS_DELTA) {
-			off_t ofs = entry->offset - entry->delta->offset;
+			off_t ofs = entry->idx.offset - entry->delta->idx.offset;
 			unsigned pos = sizeof(dheader) - 1;
 			dheader[pos] = ofs & 127;
 			while (ofs >>= 7)
