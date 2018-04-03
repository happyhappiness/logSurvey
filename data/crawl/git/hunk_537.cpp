 
 	if (!pack_to_stdout && p->index_version == 1 &&
 	    check_pack_inflate(p, &w_curs, offset, datalen, entry->size)) {
-		error("corrupt packed object for %s", sha1_to_hex(entry->idx.sha1));
+		error("corrupt packed object for %s",
+		      oid_to_hex(&entry->idx.oid));
 		unuse_pack(&w_curs);
 		return write_no_reuse_object(f, entry, limit, usable_delta);
 	}
