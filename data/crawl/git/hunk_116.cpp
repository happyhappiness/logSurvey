 			    nr_objects - nr_objects_initial);
 		stop_progress_msg(&progress, msg.buf);
 		strbuf_release(&msg);
-		sha1close(f, tail_sha1, 0);
-		hashcpy(read_sha1, pack_sha1);
-		fixup_pack_header_footer(output_fd, pack_sha1,
+		sha1close(f, tail_hash, 0);
+		hashcpy(read_hash, pack_hash);
+		fixup_pack_header_footer(output_fd, pack_hash,
 					 curr_pack, nr_objects,
-					 read_sha1, consumed_bytes-20);
-		if (hashcmp(read_sha1, tail_sha1) != 0)
+					 read_hash, consumed_bytes-the_hash_algo->rawsz);
+		if (hashcmp(read_hash, tail_hash) != 0)
 			die(_("Unexpected tail checksum for %s "
 			      "(disk corruption?)"), curr_pack);
 	}
